// Independent finite AST-language interpreter. No BRE text parsing or bytecode.
// Recursive test-only enumeration is deliberately distinct from the C state VM.
import assert from 'node:assert/strict';import {wasmProbe} from './bre-wasm-probe.mjs';
const lit=s=>({tag:'literal',text:s}),any=()=>({tag:'any'}),seq=(...items)=>({tag:'sequence',items}),group=child=>({tag:'group',child}),repeat=(child,min=0,max=Infinity)=>({tag:'repeat',child,min,max}),ref=id=>({tag:'reference',id});
function label(ast,counter={id:0,preorder:0}){ast.priority=counter.preorder++;if(ast.tag==='group')ast.id=++counter.id;if(ast.child)label(ast.child,counter);if(ast.items)ast.items.forEach(x=>label(x,counter));ast.last=counter.id;return ast;}
function text(ast){switch(ast.tag){case'any':return '.';case'literal':return ast.text;case'reference':return`\\${ast.id}`;case'group':return`\\(${text(ast.child)}\\)`;case'sequence':return ast.items.map(text).join('');case'repeat':return text(ast.child)+(ast.max===Infinity&&ast.min===0?'*':`\\{${ast.min},${ast.max===Infinity?'':ast.max}\\}`);}}
function paths(ast,input,state){const caps=state.caps.map(x=>x?.slice()??null),at=state.at;
 switch(ast.tag){
 case'any':return at<input.length?[{...state,at:at+1,caps}]:[];
 case'literal':return input.startsWith(ast.text,at)?[{...state,at:at+ast.text.length,caps}]:[];
 case'reference':{const c=caps[ast.id],s=c?input.slice(...c):null;return c&&input.startsWith(s,at)?[{...state,at:at+s.length,caps}]:[];}
 case'sequence':return ast.items.reduce((states,child)=>states.flatMap(s=>paths(child,input,s)),[state]);
 case'group':{for(let id=ast.id;id<=ast.last;id++)caps[id]=null;return paths(ast.child,input,{at,caps,trace:[]}).map(s=>{s.caps[ast.id]=[at,s.at];s.trace=[...state.trace,[ast.priority,s.at-at],...s.trace];return s;});}
 case'repeat':{const results=[];function walk(state,n){if(n<ast.max){for(const next of paths(ast.child,input,state)){const empty=next.at===state.at;if(empty&&n>0&&n>=ast.min)continue;if(empty&&n+1>=ast.min){if(n+1>=ast.min)results.push(next);}else walk(next,n+1);}}if(n>=ast.min)results.push(state);}walk({at,caps,trace:[]},0);return results.map(s=>({...s,trace:[...state.trace,[ast.priority,s.at-at],...s.trace]}));}
 }
}
function better(a,b){for(let i=0;i<a.length&&i<b.length;i++){if(a[i][0]!==b[i][0])return a[i][0]<b[i][0];if(a[i][1]!==b[i][1])return a[i][1]>b[i][1];}return a.length>b.length;}
const factories=[()=>repeat(any()),()=>repeat(group(seq(lit('a'),lit('b'),repeat(lit('a'))))),()=>lit('a'),()=>lit('b'),()=>repeat(lit('a')),()=>repeat(lit('b')),()=>repeat(lit('a'),0,2),()=>repeat(lit('a'),1,2),()=>group(repeat(lit('a'))),()=>repeat(group(repeat(lit('a')))),()=>repeat(group(repeat(lit('a'))),2,2),()=>repeat(group(seq(lit('a'),repeat(group(lit('b')))))),()=>repeat(group(seq(group(repeat(lit('a'))),repeat(lit('b')))))];
const trees=factories.map(f=>f());for(const f of factories)for(const g of factories)trees.push(seq(f(),g()));
for(const f of factories)trees.push(seq(group(f()),ref(1)));trees.push(seq(group(repeat(lit('a'))),group(repeat(lit('a'))),ref(2),ref(1)));
// Deterministic AST fuzzing never parses BRE text or uses the new compiler as an oracle.
let seed=0x425245;const choose=n=>{seed=(Math.imul(seed,1664525)+1013904223)>>>0;return seed%n;};
function randomAtom(depth){const atom=depth&&choose(3)===0?group(randomSequence(depth-1)):lit(choose(2)?'a':'b');switch(choose(4)){case 0:return repeat(atom);case 1:return repeat(atom,choose(2),2);default:return atom;}}
function randomSequence(depth){return seq(...Array.from({length:1+choose(2)},()=>randomAtom(depth)));}
for(let i=0;i<300;i++){const tree=label(randomSequence(2));if(tree.last>9)continue;trees.push(tree);if(tree.last&&i%3===0)trees.push(seq(tree,ref(1+choose(tree.last))));}
const {e,set}=wasmProbe(),stack=e.__stack_ptr.value;let checks=0;
const begin=performance.now();
for(const raw of trees){const ast=label(raw),pattern=Buffer.from(text(ast));e.bre_probe_init();set(pattern,e.bre_probe_pattern());assert.equal(e.bre_probe_compile(pattern.length),0,pattern.toString());
 for(let length=0;length<=6;length++)for(let bits=0;bits<2**length;bits++){const input=Array.from({length},(_,i)=>bits&(1<<i)?'b':'a').join('');let expected=null;
  for(let start=0;start<=length&&!expected;start++){const all=paths(ast,input,{at:start,caps:Array(10).fill(null),trace:[]});for(const s of all)if(!expected||s.at>expected.at||s.at===expected.at&&better(s.trace,expected.trace))expected={...s,start};}
  set(Buffer.from(input),e.bre_probe_input());const status=e.bre_probe_exec(length,0,0,10);assert.equal(status,expected?0:1,`${pattern}/${input}`);
  if(expected)for(let id=0;id<10;id++){const span=id?expected.caps[id]:[expected.start,expected.at],actual=Array.from({length:5},(_,j)=>e.bre_probe_capture(id,j));assert.deepEqual(actual,span?[1,...span,...span]:[0,0,0,0,0],`${pattern}/${input} group${id}`);}
  assert.equal(e.__stack_ptr.value,stack);checks++;
 }
}e.bre_probe_free();console.log(`Independent finite AST oracle / own-chain WASM: ${trees.length} patterns, ${checks} exhaustive cases; ${(performance.now()-begin).toFixed(1)} ms; memory ${e.memory.buffer.byteLength/65536} pages`);

import assert from 'node:assert/strict';import {wasmProbe} from './bre-wasm-probe.mjs';
const {e,set}=wasmProbe(),canary=0x5a5a5a5a;let checks=0;
const equal=(a,b,msg)=>{assert.deepEqual(a,b,msg);checks++;};
const raw=p=>{const b=typeof p==='string'?Buffer.from(p):Buffer.from(p);set(b,e.bre_probe_pattern());return e.bre_probe_compile(b.length);};
const compile=p=>{e.bre_probe_init();equal(raw(p),0,p);};
const exec=(s,expected,start=0,mode=0,capacity=10)=>{const b=typeof s==='string'?Buffer.from(s):Buffer.from(s);set(b,e.bre_probe_input());equal(e.bre_probe_exec(b.length,start,mode,capacity),expected,JSON.stringify(s));if(expected||!capacity)for(let i=0;i<10;i++)for(let j=0;j<5;j++)equal(e.bre_probe_capture(i,j)>>>0,canary);};
compile('.');exec([0],6);for(let n=128;n<256;n++)exec([n],3);
for(const b of [[192,128],[224,128,128],[237,160,128],[244,144,128,128],[240,159,152]]){equal(raw(b),3);exec(b,3);}
equal(raw([0]),6);equal(raw('['),2);exec('a',0);exec('😄',6,1);exec('😄',0,0,1);equal(e.bre_probe_capture(0,2),4);equal(e.bre_probe_capture(0,4),1);exec('a',0,0,0,0);exec('a',6,0,0,11);
for(const [pattern,field,bound]of [['a',2,2],['[ab]',3,2],['\\(a\\)\\(b\\)',4,2],['\\(\\(a\\)\\)',6,2],['a\\{2\\}',5,2]]){e.bre_probe_init();e.bre_probe_limit(field,bound-1);equal(raw(pattern),4);e.bre_probe_limit(field,bound);equal(raw(pattern),0);}
compile('a'.repeat(1024));exec('a'.repeat(1024),0);
compile('z');exec('a'.repeat(65535),1);exec('a'.repeat(65536),4);
e.bre_probe_init();equal(raw('a'.repeat(1025)),4);
for(let field=0;field<10;field++){e.bre_probe_init();e.bre_probe_limit(field,0);equal(raw('a'),6);}
for(const [field,ceiling]of [1024,65535,4096,4096,9,255,9,4096].entries()){e.bre_probe_init();e.bre_probe_limit(field,ceiling+1);equal(raw('a'),4);}
compile('\\(a*\\)*\\1');for(let capacity=0;capacity<=10;capacity++){exec('aaaa',0,0,0,capacity);for(let slot=capacity;slot<10;slot++)for(let field=0;field<5;field++)equal(e.bre_probe_capture(slot,field)>>>0,canary);}
compile('a\\{2\\}');e.bre_probe_limit(5,1);exec('aa',4);
compile('a*');e.bre_probe_limit(7,5);exec('aaaa',4);e.bre_probe_limit(7,6);exec('aaaa',0);
for(const field of [8,9]){compile('a*');const b=Buffer.from('aaaa');set(b,e.bre_probe_input());let low=1,high=field===8?1000000:1048576;while(low<high){const middle=Math.floor((low+high)/2);e.bre_probe_limit(field,middle);const result=e.bre_probe_exec(4,0,0,10);assert.ok(result===0||result===4);if(result===0)high=middle;else low=middle+1;}e.bre_probe_limit(field,low);exec('aaaa',0);e.bre_probe_limit(field,low-1);exec('aaaa',4);console.log(`Exact guest ${field===8?'step':'workspace'} boundary for a*/aaaa: ${low}`);}
compile('a*');e.bre_probe_limit(8,9);exec('aaaa',4); // budget exhaustion must never expose a shorter candidate
compile('\\(a*\\)*b');exec('a'.repeat(80),4); // bounded adversarial path enumeration
compile('a*');for(let i=0;i<30;i++)exec('aaaa',0);e.bre_probe_free();const pages=e.memory.buffer.byteLength/65536,stack=e.__stack_ptr.value;
const t=performance.now();for(let i=0;i<500;i++){compile('\\(a*\\)*\\1');exec('aaaaaaaaaaaa',0);e.bre_probe_free();}equal(e.memory.buffer.byteLength/65536,pages);equal(e.__stack_ptr.value,stack);
console.log(`BRE own-chain resource/encoding/atomicity: ${checks} checks; 500 compile/exec/free in ${(performance.now()-t).toFixed(1)} ms; stable ${pages} pages`);

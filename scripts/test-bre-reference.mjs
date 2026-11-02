// Adjudicate three system-reference discrepancies with independent arithmetic
// decompositions, not expectations obtained from either regex implementation.
import assert from 'node:assert/strict';import {spawnSync,execFileSync} from 'node:child_process';import fs from 'node:fs';import {fileURLToPath} from 'node:url';import {wasmProbe} from './bre-wasm-probe.mjs';
process.chdir(fileURLToPath(new URL('..',import.meta.url)));
const guest=process.argv.includes('--native-only')?null:wasmProbe(),e=guest?.e,set=guest?.set,allA=(s,first,end)=>{for(let i=first;i<end;i++)if(s[i]!=='a')return false;return true;};
const families=[
 ['\\(a*\\)\\(a*\\)\\2\\1',s=>{let r=0;while(s[r]==='a')r++;const k=Math.floor(r/2);return[[0,2*k],[0,k],[k,k]];}],
 ['\\(a*\\)\\{0,2\\}',s=>{let r=0;while(s[r]==='a')r++;return[[0,r],[0,r]];}],
 ['\\(\\(a*\\)b*\\)*\\2',s=>{
  let selected={end:0,outer:0,first:0,inner:0};
  for(let n=0;n<=s.length;n++)for(let x=0;x<=s.length-n;x++){
   let first;if(x===0){if(n&&s[n-1]!=='b')continue;let onlyB=true;for(let i=0;i<n;i++)if(s[i]!=='b')onlyB=false;first=!n||onlyB?0:n-1;}
   else{let b=n;while(b&&s[b-1]==='b')b--;first=b-x;if(first<0||!allA(s,first,b)||!allA(s,n,n+x))continue;}
   const end=n+x;if(end>selected.end||end===selected.end&&n>selected.outer)selected={end,outer:n,first,inner:first+x};
  }
  return[[0,selected.end],[selected.first,selected.outer],[selected.first,selected.inner]];
 }]
];
let checks=0;
for(const [pattern,expected]of families){if(guest){e.bre_probe_init();set(Buffer.from(pattern),e.bre_probe_pattern());assert.equal(e.bre_probe_compile(Buffer.byteLength(pattern)),0);}
 for(let length=0;length<=8;length++)for(let bits=0;bits<2**length;bits++){const input=Array.from({length},(_,i)=>bits&(1<<i)?'b':'a').join(''),spans=expected(input),wanted=Array.from({length:10},(_,id)=>spans[id]?[1,...spans[id],...spans[id]]:[0,0,0,0,0]);
  if(guest){set(Buffer.from(input),e.bre_probe_input());assert.equal(e.bre_probe_exec(length,0,0,10),0);const actual=Array.from({length:10},(_,id)=>Array.from({length:5},(_,field)=>e.bre_probe_capture(id,field)));assert.deepEqual(actual,wanted,`arithmetic oracle / WASM ${pattern}/${input}`);}
  const lines=execFileSync('build/bre/probe',[pattern,input],{encoding:'utf8'}).trim().split('\n');assert.equal(Number(lines[0].split(' ')[0]),0);assert.deepEqual(lines.slice(1).map(s=>s.split(',').map(Number)),wanted,`arithmetic oracle / native ${pattern}/${input}`);checks++;
 }
}if(guest)e.bre_probe_free();
const diagnostic=spawnSync('build/bre/system-reference',[],{encoding:'utf8'});assert.ok(!diagnostic.error,diagnostic.error?.message);fs.writeFileSync('build/bre/system-reference.log',diagnostic.stdout+diagnostic.stderr);process.stdout.write(diagnostic.stdout);
assert.equal(diagnostic.signal,null);assert.ok(diagnostic.status===0||diagnostic.status===1);
const differences=[...diagnostic.stdout.matchAll(/^pattern differences (.+): (\d+)$/gm)];
for(const [,pattern,count]of differences){assert.ok(families.some(([p])=>p===pattern),`Unreviewed reference discrepancy: ${pattern}`);assert.ok(Number(count)>0);}
if(process.platform==='darwin'){assert.equal(diagnostic.status,1);assert.deepEqual(differences.map(([,p,n])=>[p,Number(n)]),families.map(([p],i)=>[p,[31,64,68][i]]));}
console.log(`Independent arithmetic / native${guest?' / own-chain WASM':''}: ${checks} cases pass. Raw libc diagnostic exit ${diagnostic.status}; ${differences.length} explicitly adjudicated families, no undisclosed differences. Not full POSIX/locale conformance.`);

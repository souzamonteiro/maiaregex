import assert from 'node:assert/strict';import {wasmProbe} from './bre-wasm-probe.mjs';
const {e,set}=wasmProbe('../build/bre/probe-fault.wasm'),pattern=Buffer.from('\\(a*\\)*\\1'),input=Buffer.from('aaaaaaaaaaaa');
e.bre_probe_init();set(pattern,e.bre_probe_pattern());set(input,e.bre_probe_input());e.bre_fault_reset(0);assert.equal(e.bre_probe_compile(pattern.length),0);const compileCalls=e.bre_fault_count(),compilePeak=e.bre_fault_peak_bytes();e.bre_probe_free();assert.equal(e.bre_fault_bytes(),0);
for(let fail=1;fail<=compileCalls;fail++){e.bre_fault_reset(fail);assert.equal(e.bre_probe_compile(pattern.length),5,`compile allocation ${fail}`);assert.equal(e.bre_fault_bytes(),0);assert.equal(e.bre_fault_invalid(),0);}
e.bre_fault_reset(0);assert.equal(e.bre_probe_compile(pattern.length),0);const retained=e.bre_fault_bytes();e.bre_fault_reset(0);assert.equal(e.bre_probe_exec(input.length,0,0,10),0);const execCalls=e.bre_fault_count(),execPeak=e.bre_fault_peak_bytes()-retained;
for(let fail=1;fail<=execCalls;fail++){e.bre_fault_reset(fail);assert.equal(e.bre_probe_exec(input.length,0,0,10),5,`exec allocation ${fail}`);for(let i=0;i<10;i++)for(let j=0;j<5;j++)assert.equal(e.bre_probe_capture(i,j)>>>0,0x5a5a5a5a);assert.equal(e.bre_fault_bytes(),retained);assert.equal(e.bre_fault_invalid(),0);}
e.bre_fault_reset(0);e.bre_probe_free();assert.equal(e.bre_fault_bytes(),0);
console.log(`Own-chain guest fault injection: ${compileCalls} compile + ${execCalls} exec sites; NOMEM/unchanged outputs/no leaks; peaks ${compilePeak} compile / ${execPeak} exec heap bytes`);

// Run after the ordinary own-chain build has refreshed generated/bre-compiler.c.
import fs from 'node:fs';import path from 'node:path';import assert from 'node:assert/strict';import {createRequire} from 'node:module';import {fileURLToPath} from 'node:url';
const root=fileURLToPath(new URL('..',import.meta.url)),require=createRequire(import.meta.url),cpp=path.join(root,'tools/maiacpp');const {compileSource}=require(path.join(cpp,'maiac/compiler/c-compiler.js'));const {preprocessCSource}=require(path.join(cpp,'maiac/compiler/c-preprocessor.js'));fs.mkdirSync(path.join(root,'build/bre'),{recursive:true});const linked=path.join(root,'build/bre/fault-linked.c');
const include=p=>`#include "${p}"\n`;
// Instrument the library translation unit, not the allocator implementation.
// Separate preprocessing preserves macro boundaries with MaiaC's documented
// collect-then-expand preprocessor; no host parser or source patch is involved.
const runtime=[path.join(cpp,'maiac/src/stdlib.c'),path.join(cpp,'maiac/src/string.c'),path.join(root,'tests/bre/fault-runtime.c')].map(include).join('');
const library='#define MAIACPP_USE_C_ALLOCATOR\n#define malloc bre_fault_malloc\n#define calloc bre_fault_calloc\n#define realloc bre_fault_realloc\n#define free bre_fault_free\n'+[path.join(root,'maia_regex.c'),path.join(root,'maia_bre.c'),path.join(root,'generated/bre-compiler.c'),path.join(root,'tests/bre/probe.c')].map(include).join('');
const options={sourcePath:linked,resolveSystemIncludes:true,includeDirs:[path.join(cpp,'maiac/compiler/include'),path.join(cpp,'maiac/include')]};
fs.writeFileSync(linked,preprocessCSource(library,options)+'\n'+preprocessCSource(runtime,options));
const result=compileSource(fs.readFileSync(linked,'utf8'),{sourcePath:linked,resolveSystemIncludes:true,validate:true,serializeParseTrees:false});assert.ok(result.wasm,result.validationError?.message);fs.writeFileSync(path.join(root,'build/bre/probe-fault.wasm'),Buffer.from(result.wasm));console.log(`Instrumented C89 guest compiler/executor: ${result.wasm.length} bytes; no production allocator hooks`);

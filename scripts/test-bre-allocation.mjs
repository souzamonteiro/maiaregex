import fs from 'node:fs';import {execFileSync as run} from 'node:child_process';import {fileURLToPath} from 'node:url';process.chdir(fileURLToPath(new URL('..',import.meta.url)));
const dir='build/bre-allocation';fs.mkdirSync(dir,{recursive:true});
const common=['-pedantic-errors','-O1','-g','-fsanitize=address,undefined','-fno-omit-frame-pointer'];
const aliases=['-include','tests/bre/alloc.h','-Dmalloc=bre_test_malloc','-Dcalloc=bre_test_calloc','-Drealloc=bre_test_realloc','-Dfree=bre_test_free'];
for(const [src,name,cpp]of [['maia_bre.c','runtime',false],['maia_bre_compile.cpp','compiler',true],['maia_regex.c','ordered',false]])run(cpp?'clang++':'clang',[cpp?'-std=c++98':'-std=c89',...common,...aliases,'-I.','-c',src,'-o',`${dir}/${name}.o`],{stdio:'inherit'});
run('clang',['-std=c89',...common,'tests/bre/alloc.c',...['runtime','compiler','ordered'].map(n=>`${dir}/${n}.o`),'-o',`${dir}/test`],{stdio:'inherit'});run(`${dir}/test`,process.argv.includes('--measure')?['--measure']:[],{stdio:'inherit'});

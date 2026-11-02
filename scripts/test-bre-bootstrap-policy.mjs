// Check the real policy and Git's behavior without touching project checkouts.
import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
const owner=fileURLToPath(new URL('..',import.meta.url));
const git=(cwd,...args)=>execFileSync('git',['-c','protocol.file.allow=always',
  '-c','user.name=Bootstrap Test','-c','user.email=bootstrap-test@invalid',
  '-c','commit.gpgsign=false','-C',cwd,...args],{encoding:'utf8',stdio:['ignore','pipe','pipe']}).trim();
assert.equal(git(owner,'config','-f','.gitmodules','--get','submodule.tools/maiacpp.update'),'none');
const root=fs.mkdtempSync(path.join(os.tmpdir(),'maia-bootstrap-policy-'));
function init(name){const directory=path.join(root,name);fs.mkdirSync(directory);git(directory,'init','-b','main');return directory;}
function commit(directory,text){fs.writeFileSync(path.join(directory,'data'),text);git(directory,'add','.');git(directory,'commit','-m',text);return git(directory,'rev-parse','HEAD');}
try{
  const leaf=init('leaf'),old=commit(leaf,'old');
  const compiler=init('compiler');commit(compiler,'compiler');
  git(compiler,'submodule','add',leaf,'leaf');git(compiler,'commit','-am','pin old leaf');
  commit(leaf,'new remote leaf');
  const library=init('library');commit(library,'library');
  git(library,'submodule','add',compiler,'tools/maiacpp');
  git(library,'config','-f','.gitmodules','submodule.tools/maiacpp.update','none');
  git(library,'add','.gitmodules','tools/maiacpp');git(library,'commit','-m','fixed historical bootstrap');
  const consumer=path.join(root,'consumer');git(root,'clone','--recurse-submodules',library,consumer);
  const pinned=path.join(consumer,'tools/maiacpp');
  assert.equal(fs.existsSync(path.join(pinned,'.git')),false,'ordinary consumers skip development bootstrap');
  git(consumer,'submodule','update','--init','--checkout','--recursive','tools/maiacpp');
  assert.equal(git(path.join(pinned,'leaf'),'rev-parse','HEAD'),old,'explicit initialization uses recorded pins');
  git(consumer,'submodule','update','--remote','--recursive');
  assert.equal(git(path.join(pinned,'leaf'),'rev-parse','HEAD'),old,'remote recursion never enters historical bootstrap');
  assert.equal(git(pinned,'status','--porcelain'),'');
  console.log('BRE bootstrap policy: recursive consumers skip development tools; explicit initialization and historical descendant pins remain reproducible');
}finally{fs.rmSync(root,{recursive:true,force:true});}

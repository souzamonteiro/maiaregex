import fs from 'node:fs';import assert from 'node:assert/strict';import {createRequire} from 'node:module';const require=createRequire(import.meta.url);
const Parser=require('../generated/bre-parser.cjs'),{ParseTreeCollector}=require('../tools/maiacpp/maiacc/parser-generator/parse-tree-collector.js');
export function parseBre(source){const collector=new ParseTreeCollector();const parser=new Parser(source,collector);collector.parse(parser);return {parser,collector};}
const cases=JSON.parse(fs.readFileSync(new URL('../tests/bre/syntax-cases.json',import.meta.url)));
for(const source of cases.valid){const {parser}=parseBre(source);assert.equal(parser.tokens.slice(0,-1).map(t=>t.value).join(''),source);}
for(const source of cases.invalid)assert.throws(()=>parseBre(source),source);
for(const [source,types] of [['$',['END_DOLLAR']],['$a',['DOLLAR','LETTER']],['\\$',['BACKSLASH','END_DOLLAR']],['[.]',['OPEN_SPECIAL','DOT','CLOSE']],['[[]',['OPEN','OPEN','CLOSE']]])assert.deepEqual(parseBre(source).parser.tokens.slice(0,-1).map(t=>t.type),types,source);
console.log(`PASS generated BRE JavaScript: ${cases.valid.length} valid/${cases.invalid.length} invalid,exact source/span transport and anchor/class contexts`);

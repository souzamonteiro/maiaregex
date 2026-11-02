struct Token {unsigned int type;const char* value;unsigned int length,start,end;};
static struct Token tokens[4];
static char source[1025];
unsigned int offset(unsigned int i){return (unsigned int)(tokens[i].value-source);}

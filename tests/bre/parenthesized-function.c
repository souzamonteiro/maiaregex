void (release)(void *pointer);
void release(void *pointer) { (void)pointer; }
int test_entry(void) { release(0); return 7; }

#ifndef BRE_TEST_ALLOC_H
#define BRE_TEST_ALLOC_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
void* bre_test_malloc(size_t);
void* bre_test_calloc(size_t,size_t);
void* bre_test_realloc(void*,size_t);
void bre_test_free(void*);
#ifdef __cplusplus
}
#endif
#endif

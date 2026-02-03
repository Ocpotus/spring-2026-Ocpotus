#include <stdlib.h>

#include "memory.h"


void *memory_new(size_t size) {
	return malloc(size);
}

void memory_delete(void *ptr) {
	free(ptr);
}

void *memory_resize(void *ptr, size_t size) {
	return realloc(ptr, size);
}

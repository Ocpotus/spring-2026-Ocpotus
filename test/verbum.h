#ifndef VERBUM_H
#define VERBUM_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct VerbumContext {
	struct {
		void *(*new)(size_t n);
		void (*delete)(void *ptr);
		void *(*resize)(void *ptr, size_t size);
		void *(*copy)(void *data, size_t size);
	} memory;
	struct {
		//void *stream;
		const char *(*source)(void *stream);
		uint32_t (*get)(void *stream);
		uint32_t (*unget)(void *stream);
		uint32_t (*tell)(void *stream);
		bool (*at_end)(void *stream);
		void *(*open)(const char *path);
		void (*close)(void *stream);
		char *(*copy_from)(void *stream, size_t offset, size_t nbytes);
	} io;
} VerbumContext;



#endif

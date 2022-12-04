#include <stdlib.h>
#include <stdio.h>
#include "common.h"

void* safe_malloc(size_t _Size) {
	void* mem = malloc(_Size);
	if (mem == NULL) {
		printf("elfogyott a memoria");
		exit(out_of_memory_error);
	}
	return mem;
}
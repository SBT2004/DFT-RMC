#define _CRTDBG_MAP_ALLOC
#pragma once

#include <stdbool.h>

typedef enum {
	config_error = -1,
	argument_error = -2,
	out_of_memory_error = -3,
	matrix_error = -4	
} exit_codes;

#ifndef PI
#define PI 3.14159265358979323846
#endif

void* safe_malloc(size_t _Size);

bool lazy_equal(const double a, const double b);

bool is_zero(const double a);
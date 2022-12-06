#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include <crtdbg.h>
#include <cfloat>
#include <math.h>

// malloc, beépített hibakezeléssel
void* safe_malloc(size_t _Size) {
	void* mem = malloc(_Size);
	if (mem == NULL) {
		printf("elfogyott a memoria");
		exit(out_of_memory_error);
	}
	return mem;
}

// összehasonlít két valós számot, és megmondja hogy hibahatáron belül megegyeznek-e
bool lazy_equal(const double a, const double b) {
	const double myepsilon = DBL_MIN * 10.0;
	return fabs(a - b) <= myepsilon;
}

// ha egy valós szám hibahatáron belül 0 true-t, ha nem false-ot ad vissza
bool is_zero(const double a) {
	return lazy_equal(a, 0.0);
}
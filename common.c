#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include <crtdbg.h>
#include <cfloat>
#include <math.h>

// malloc, be�p�tett hibakezel�ssel
void* safe_malloc(size_t _Size) {
	void* mem = malloc(_Size);
	if (mem == NULL) {
		printf("elfogyott a memoria");
		exit(out_of_memory_error);
	}
	return mem;
}

// �sszehasonl�t k�t val�s sz�mot, �s megmondja hogy hibahat�ron bel�l megegyeznek-e
bool lazy_equal(const double a, const double b) {
	const double myepsilon = DBL_MIN * 10.0;
	return fabs(a - b) <= myepsilon;
}

// ha egy val�s sz�m hibahat�ron bel�l 0 true-t, ha nem false-ot ad vissza
bool is_zero(const double a) {
	return lazy_equal(a, 0.0);
}
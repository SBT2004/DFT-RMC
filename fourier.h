// (C) Soczó Bálint
#pragma once

#include "matrix.h"

matrix* generate_q(double dq, double min, double max);

matrix* generate_rgr(const matrix* r, const matrix* gr);

matrix* apply_sin_to_all_elements(const matrix* m);

matrix* discrete_fourier_transform(const matrix* sinqr, const matrix* rgr, const matrix* q, double ndens, double dq);



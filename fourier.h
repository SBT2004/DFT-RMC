#pragma once

matrix* generate_q(double dq, double min, double max);
matrix* generate_rgr(matrix* r, matrix* gr);
matrix* sin_qr(matrix* m);
matrix* discrete_fourier_transform(matrix* sinqr, matrix* rgr, matrix* q, double ndens, double dq);



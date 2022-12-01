#include <stdlib.h>
#include "matrix.h"
#include "Fourier.h"
#include "math.h"

matrix* generate_q(double dq, double min, double max) {
	double q_val = min;
	if (dq == 0)
	{
		exit(-1);
	}
	int len = ((max - min) / dq) + 1;
	if (len == 0)
	{
		exit(0);
	}
	matrix* q_mat = create_matrix(len, 1);

	for (int r = 0; r < len; r++)
	{
		set_value(q_mat, r, 0, q_val);
		q_val += dq;
	}

	return q_mat;
}

matrix* generate_rgr(matrix* r, matrix* gr) {
	int col1 = r->ncol;
	matrix* rgr = create_matrix(1, col1);
	for (int col = 0;col < col1;col++) {
		set_value(rgr, 0, col, (get_value(r, 0, col) * (get_value(gr, 0, col) - 1.0)));
	}
	return rgr;
}

matrix* sin_qr(matrix* m) {
	int mat_row = m->nrow, mat_col = m->ncol;
	matrix* mat_out = create_matrix(mat_row, mat_col);
	for (int row = 0; row < mat_row; row++)
	{
		for (int col = 0; col < mat_col; col++)
		{
			set_value(mat_out, row, col, sin(get_value(m, row, col)));
		}
	}
	return mat_out;
}

matrix* discrete_fourier_transform(matrix* sinqr, matrix* rgr, matrix* q, double ndens, double dq) {
	int rgr_row = rgr->nrow, rgr_col = rgr->ncol, q_row = q->nrow, q_col = q->ncol;
	matrix* prod_mat = matrix_product(rgr, sinqr);
	int sq_col = prod_mat->ncol;
	matrix* mat_out = create_matrix(1, sq_col);
	double k = 4 * 3.1415 * ndens * dq;
	for (int col = 0; col < sq_col; col++)
	{
		set_value(mat_out, 0, col, k * (get_value(prod_mat, 0, col) / get_value(q, col, 0)));
	}
	return mat_out;
}
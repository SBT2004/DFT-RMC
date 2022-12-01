#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void init_zero(matrix* m, int nrow, int ncol)
{
	for (int row = 0; row < nrow; row++)
	{
		for (int col = 0; col < ncol; col++)
		{
			set_value(m, row, col, 0.0);
		}
	}
}

matrix* create_zero_matrix(int nrow, int ncol)
{
	matrix* m = create_matrix(nrow, ncol);

	init_zero(m, nrow, ncol);

	return m;
}

matrix* create_matrix_and_initialize(int nrow, int ncol, double initial_values[])
{
	matrix* m = create_matrix(nrow, ncol);

	for (int row = 0; row < nrow; row++)
	{
		for (int col = 0; col < ncol; col++)
		{
			set_value(m, row, col, initial_values[row * m->ncol + col]);
		}
	}

	return m;
}

matrix* create_matrix(int nrow, int ncol)
{
	matrix* m = malloc(sizeof(matrix) + sizeof(double) * (nrow * ncol));

	m->nrow = nrow;
	m->ncol = ncol;
	m->len = nrow * ncol;

	return m;
}

void set_value(matrix* m, int row, int col, double value) {
	m->val[row * m->ncol + col] = value;
}

double get_value(matrix* m, int row, int col) {
	if (row >= m->nrow || col >= m->ncol)
	{
		//hiba
		exit(-1);
	}

	return m->val[row * m->ncol + col];
}

matrix* matrix_product(matrix* m1, matrix* m2) {
	int row1 = m1->nrow, col1 = m1->ncol, row2 = m2->nrow, col2 = m2->ncol;
	matrix* mat_out = create_matrix(row1, col2);
	if (col1 != row2)
	{
		exit(-2);
	}

	for (int row = 0;row < row1;row++) {
		for (int col = 0;col < col2;col++) {
			double sum = 0;
			for (int k = 0;k < col1;k++) {
				sum += get_value(m1, row, k) * get_value(m2, k, col);
			}
			set_value(mat_out, row, col, sum);

		}
	}
	return mat_out;
}

matrix* transpose(matrix* m)
{
	int row_in = m->nrow, col_in = m->ncol;
	int row_out = m->ncol, col_out = m->nrow;
	matrix* transposed = create_matrix(row_out, col_out);
	for (int r = 0; r < row_in; r++)
	{
		for (int c = 0; c < col_in; c++)
		{
			set_value(transposed, c, r, get_value(m, r, c));
		}

	}
	return transposed;
}
void visualize(matrix* m) {
	int nrow = m->nrow, ncol = m->ncol;
	for (int row = 0; row < nrow; row++)
	{
		for (int col = 0; col < ncol; col++)
		{
			printf("%5.2lf ", get_value(m, row, col));
		}
		printf("\n");
	}
}
matrix** matrix_to_vectors(matrix* mat_in) {
	int col_mat = mat_in->ncol, row_mat = mat_in->nrow;
	matrix** arr = (matrix**)malloc(sizeof(double*)*col_mat);
	for (int col = 0;col < col_mat;col++)
	{
		matrix* temp = create_matrix(row_mat, 1);
		for (int row = 0; row < row_mat; row++)
		{
			set_value(temp, row, 0, get_value(mat_in, row, col));
		}
		arr[col] = temp;
	}

	return arr;
}

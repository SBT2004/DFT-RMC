#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "common.h"

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

// Létrehoz egy mátrixot a heapen.
// A visszadott pointert a hívónak fel kell szabadítania.
matrix* create_matrix(int nrow, int ncol)
{
	if (nrow <= 0 || ncol <= 0)
	{
		printf("ilyen meretu matrixot nem lehet letrehozni");
		exit(argument_error);
	}

	//a mátrix tényleges elemei a mátrix struktúra után vannak
	//https://www.geeksforgeeks.org/struct-hack/
	matrix* m = safe_malloc(sizeof(matrix) + sizeof(double) * (nrow * ncol));

	m->nrow = nrow;
	m->ncol = ncol;
	m->len = nrow * ncol;

	return m;
}

//átírja m mátrix rowadik sorának és coladik oszlopának értékét value-ra
void set_value(matrix* m, int row, int col, double value) {
	if (row >= m->nrow)
	{
		printf("row parameter tulcimez a matrixon");
		exit(argument_error);
	}

	if (col >= m->ncol)
	{
		printf("col parameter tulcimez a matrixon");
		exit(argument_error);
	}

	m->val[row * m->ncol + col] = value;
}

// Visszadja m mátrix rowadik sorának és coladik oszlopának az értékét.
// A legelső sor és oszlop indexe 0.
double get_value(const matrix* m, int row, int col) {
	if (row >= m->nrow)
	{
		printf("row parameter tulcimez a matrixon");
		exit(argument_error);
	}

	if (col >= m->ncol)
	{
		printf("col parameter tulcimez a matrixon");
		exit(argument_error);
	}

	return m->val[row * m->ncol + col];
}

// mátrixszorzást hajt végre m1-en és m2-en,
// egy új mátrixban visszaadja a szorzatot
matrix* matrix_product(const matrix* m1, const matrix* m2) {
	int row1 = m1->nrow, col1 = m1->ncol, row2 = m2->nrow, col2 = m2->ncol;

	if (col1 != row2)
	{
		printf("ez a ket matrix nem szorozhato ossze");
		exit(argument_error);
	}

	matrix* mat_out = create_matrix(row1, col2);

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

//visszadja a mátrix transzponáltját egy új mátrixban
matrix* transpose(const matrix* m)
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

//kiírja a mátrixot a konzolba
void visualize(const matrix* m) {
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

//szétszedi a mátrixot egyoszlopos mátrixok tömbjére
matrix** matrix_to_vectors(const matrix* mat_in) {
	int col_mat = mat_in->ncol, row_mat = mat_in->nrow;
	matrix** arr = (matrix**)safe_malloc(sizeof(double*) * col_mat);
	for (int col = 0;col < col_mat;col++)
	{
		//egy oszlop felépítése
		matrix* temp = create_matrix(row_mat, 1);
		for (int row = 0; row < row_mat; row++)
		{
			set_value(temp, row, 0, get_value(mat_in, row, col));
		}
		arr[col] = temp;
	}

	return arr;
}

//összadja a mátrix rowadik sorát a row_to_add-adik sorral,
//az eredményt berakja a rowadik sorba
void row_addition(matrix* mat, int row, int row_to_add) {
	for (int i = 0; i < mat->ncol; i++)
	{
		set_value(mat, row, i, get_value(mat, row, i) + get_value(mat, row_to_add, i));
	}
}

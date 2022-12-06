// (C) Socz� B�lint
#pragma once

#define _CRTDBG_MAP_ALLOC

// egy k�tdimenzi�s m�trixot �r le
typedef struct {
	int nrow; //sorok sz�ma
	int ncol; //oszlopok sz�ma
	int len; // a sorok �s oszlopok sz�m�nak szorzata, mem�riakezel�shez
	double val[]; //�rt�kek egy dinamikus t�mbben
} matrix;

matrix* create_matrix(int nrow, int ncol);

double get_value(const matrix* m, int row, int col);

void set_value(matrix* m, int row, int col, double value);

matrix** matrix_to_vectors(const matrix* mat_in);

matrix* matrix_product(const matrix* m1, const matrix* m2);

matrix* transpose(const matrix* m);

void visualize(const matrix* m);

void row_addition(matrix* mat, int row, int row_to_add);

matrix* create_zero_matrix(int nrow, int ncol);

matrix* create_matrix_and_initialize(int nrow, int ncol, double initial_values[]);

#pragma once

typedef struct {
	int nrow; //sorok sz�ma
	int ncol; //oszlopok sz�ma
	int len; // a sorok �s oszlopok sz�m�nak szorzata, mem�riakezel�shez
	double val[]; //�rt�kek egy dinamikus t�mbben
} matrix;

matrix* create_zero_matrix(int nrow, int ncol);

matrix* create_matrix_and_initialize(int nrow, int ncol, double initial_values[]);

matrix* create_matrix(int nrow, int ncol);

void set_value(matrix* m, int row, int col, double value);

matrix* matrix_product(matrix* m1, matrix* m2);

matrix* transpose(matrix* m);

double get_value(matrix* m, int row, int col);

void visualize(matrix* m);

matrix** matrix_to_vectors(matrix* mat_in);


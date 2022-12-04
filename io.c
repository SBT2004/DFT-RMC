#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "matrix.h"
#include "io.h"
#include "common.h"

#pragma warning(disable:4996)

// 
matrix* read_r_and_gr_from_csv(const char* path_to_csv) {
	FILE* fp = fopen(path_to_csv, "r");

	if (fp == NULL)
	{
		printf("path_to_csv nem letezo faljra hivatkozik: %s", path_to_csv);
		exit(argument_error);
	}

	double r = 0, gr = 0;
	int count = 0;
	// a két sorvége (cr, lf) karakter miatt (feltételezve Windowsos
	// fájlvége jeleket) a vegen %*c-k
	// meghatározzuk a létrehozandó mátrix hosszát
	while (fscanf(fp, "%lf\t%lf[^\n]%*c%*c", &r, &gr) != EOF)
	{
		count++;
	}

	// visszaállítja a file pointert, hogy majd 
	// kiolvashassuk újra a fájl tartalmát
	fseek(fp, 0, SEEK_SET);

	matrix* m = create_matrix(count, 2);
	
	int k = 0;
	while (fscanf(fp, "%lf\t%lf[^\n]%*c%*c", &r, &gr) != EOF)
	{
		// R nem lehet 0 vagy negatív, növekvő sorrendben kell lennie.
		// Gr nem lehet negatív.
		// Ezeket le lehetne ellenőrizni.
		set_value(m, k, 0, r);
		set_value(m, k, 1, gr);
		k++;
	}

	fclose(fp);

	return m;
}

// 
void csv_out(const char* csv_out_file_path, const matrix* q_mat, const matrix* sq_mat)
{
	FILE* fp = fopen(csv_out_file_path, "w");

	for (int i = 0; i < q_mat->nrow; i++)
	{
		fprintf(fp, "%.3lf\t%.3lf\n", q_mat->val[i], sq_mat->val[i]);
	}

	fclose(fp);
}

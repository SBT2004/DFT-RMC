#include "main.h"
#include "matrix.h"
#include <stdio.h>
#pragma warning(disable:4996)

matrix* read_csv() {
	FILE* fp = fopen("C:\\temp\\out.txt", "r");
	double a = 0, b = 0;
	int count = 0;
	// a ket newline karakter miatt a vegen %*c-k
	// meghat�rozzuk a l�trehozand� m�trix hossz�t
	while (fscanf(fp, "%lf\t%lf[^\n]%*c%*c", &a, &b) != EOF)
	{
		count++;
	}
	//int fseek(FILE * stream, long int offset, int whence)
	// vissa�ll�tja a pointert, hogy majd be�ll�thassuk a m�trix �rt�keit
	fseek(fp, 0, SEEK_SET);
	matrix* m = create_matrix(count, 2);
	int k = 0;
	while (fscanf(fp, "%lf\t%lf[^\n]%*c%*c", &a, &b) != EOF)
	{
		set_value(m, k, 0, a);
		set_value(m, k, 1, b);
		k++;
	}
	fclose(fp);
	return m;
}
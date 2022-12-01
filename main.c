#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "fourier.h"
#include "matrix.h"

int main() {
	config cfg = read_config();
	matrix* input = read_csv();
	matrix** input_mat_arr = matrix_to_vectors(input);
	matrix* r_mat = input_mat_arr[0];
	matrix* gr_mat = input_mat_arr[1];
	visualize (r_mat);

	double rho = 4.3, M = 79;
	double ndens = calculate_number_density(rho,M);
	double dq = 0.5, min = 0.5, max = 20.0;
	matrix* q_mat = generate_q(dq, min, max);
	//matrix* r_mat = create_matrix_and_initialize(1, 5, r);
	//matrix* gr_mat = create_matrix_and_initialize(1, 5, gr);
	matrix* rgr_mat = generate_rgr(r_mat, gr_mat);

	matrix* qr_mat = matrix_product(q_mat,r_mat);
	matrix* sinqr_mat = sin_qr(qr_mat);
	matrix* tran_sinqr = transpose(sinqr_mat);
	matrix* sq_mat = discrete_fourier_transform(tran_sinqr, rgr_mat, q_mat, ndens, dq);
	for (int i = 0; i < sinqr_mat->nrow; i++)
	{
		printf("%.3lf\t%.3lf\n",q_mat->val[i],sq_mat->val[i]);
	}
	
#pragma warning(disable:4996)
	FILE* fp= fopen("C:\\temp\\out.txt", "w");
	for (int i = 0; i < sinqr_mat->nrow; i++)
	{
		fprintf(fp, "%.3lf\t%.3lf\n", q_mat->val[i], sq_mat->val[i]);
	}
	fclose(fp);

	//system("\"C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\excel.exe\" C:\\temp\\out.txt");


	//visualize(sinqr_mat);
	free(q_mat);
	free(r_mat);
	free(gr_mat);
	free(rgr_mat);
	free(qr_mat);
	free(sinqr_mat);
	free(tran_sinqr);
	free(sq_mat);

	
	return 0;
}
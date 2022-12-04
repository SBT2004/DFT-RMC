#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "density.h"
#include "fourier.h"
#include "main.h"
#include "matrix.h"
#include "io.h"

//nem akarjuk a secure string függvényeket használni
#pragma warning(disable:4996)

int main() {

	// Visual Studioból tesztelve a projectben található
	// config.txt-t ott van, ahol a project maga.
	// Más fordítás esetén az alábbi elérési utat át kell írni.

	const char* base_path = "";
	//const char* base_path = "c:\\temp";

	char input_path[256] = { 0 };
	strcpy(input_path, base_path);
	strcat(input_path, "input.txt");

	char config_path[256] = { 0 };
	strcpy(config_path, base_path);
	strcat(config_path, "config.txt");

	char output_path[256] = { 0 };
	strcpy(output_path, base_path);
	strcat(output_path, "config.txt");

	// Input beolvasása
	matrix* input = read_r_and_gr_from_csv(input_path);
	matrix** input_mat_arr = matrix_to_vectors(input);
	matrix* r_mat = input_mat_arr[0];
	matrix* gr_mat = input_mat_arr[1];

	// Config beolvasása
	config cfg = read_config(config_path);
	double dq = cfg.dq;
	double min = cfg.min;
	double max = cfg.max;
	double m = cfg.molar_mass;
	double rho = cfg.rho;

	//bemenő adatokból kiindulási mátrixok és konstansok generálása
	double ndens = calculate_number_density(rho, m);
	matrix* q_mat = generate_q(dq, min, max);
	//visualize(q_mat);
	matrix* rgr_mat = generate_rgr(r_mat, gr_mat);
	//visualize(rgr_mat);
	matrix* qr_mat = matrix_product(q_mat, r_mat);
	matrix* sinqr_mat = apply_sin_to_all_elements(qr_mat);
	matrix* tran_sinqr = transpose(sinqr_mat);
	matrix* sq_mat = discrete_fourier_transform(tran_sinqr, rgr_mat, q_mat, ndens, dq);

	csv_out(output_path, q_mat, sq_mat);
	
	//Ha meg akarjuk nézni excelben
	system("\"C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\excel.exe\" C:\\temp\\out.txt");

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

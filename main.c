// (C) Soczó Bálint
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"
#include "density.h"
#include "fourier.h"
#include "io.h"
#include "matrix.h"

//nem akarjuk a secure string függvényeket használni
#pragma warning(disable:4996)

int main() {

	// Visual Studioból tesztelve a projectben található
	// config.txt-t ott van, ahol a project maga.
	// Más fordítás esetén az alábbi elérési utat át kell írni:
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
	strcat(output_path, "output.txt");

	// Input beolvasása
	matrix* input = read_r_and_gr_from_csv(input_path);
	matrix** input_mat_arr = matrix_to_vectors(input);
	matrix* r_mat = input_mat_arr[0];
	matrix* gr_mat = input_mat_arr[1];
	matrix* tran_r_mat = transpose(r_mat);
	matrix* tran_gr_mat = transpose(gr_mat);

	// Config beolvasása
	config cfg = read_config(config_path);
	validate_config(cfg);
	double dq = cfg.dq;
	double min = cfg.min;
	double max = cfg.max;
	double m = cfg.molar_mass;
	double rho = cfg.rho;

	double ndens = calculate_number_density(rho, m);
	
	//bemenő adatokból kiindulási mátrixok generálása
	matrix* q_mat = generate_q(dq, min, max);
	//visualize(q_mat);
	matrix* rgr_mat = generate_rgr(tran_r_mat, tran_gr_mat);
	//visualize(rgr_mat);
	matrix* qr_mat = matrix_product(q_mat, tran_r_mat);
	//visualize(qr_mat);
	matrix* sinqr_mat = apply_sin_to_all_elements(qr_mat);
	//visualize(sinqr_mat);
	matrix* tran_sinqr = transpose(sinqr_mat);
	//visualize(tran_sinqr);
	matrix* sq_mat = discrete_fourier_transform(tran_sinqr, rgr_mat, q_mat, ndens, dq);
	//visualize(sq_mat);

	csv_out(output_path, q_mat, sq_mat);

	//Ha meg akarjuk nézni excelben
	//Az elérési utat át kell írni másik gépen
	/*char command[256] = "\"C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\excel.exe\"";
	strcat(command, " ");
	strcat(command, output_path);
	system(command);*/

	free(q_mat);
	free(r_mat);
	free(gr_mat);
	free(tran_r_mat);
	free(tran_gr_mat);
	free(rgr_mat);
	free(qr_mat);
	free(sinqr_mat);
	free(tran_sinqr);
	free(sq_mat);
	free(input_mat_arr);
	free(input);

	//Ez alapján nincs memory leak a kód egyenes ágában
	//_CrtDumpMemoryLeaks();

	return 0;
}

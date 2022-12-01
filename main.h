#pragma once
#include "matrix.h"

double calculate_number_density(double Rho, double M);
matrix* read_csv();
typedef struct {
	double rho;
	int M;
	double dq;
	double min;
	double max;
}config;
config read_config();

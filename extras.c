#include "main.h"
#include "matrix.h"

double calculate_number_density(double Rho, double M){
	double Ndens = (Rho * 0.6) / (M);
	return Ndens;
}
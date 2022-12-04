#include "main.h"
#include "matrix.h"
#include "density.h"

// 
double calculate_number_density(double rho, double molar_mass){
	return (rho * 0.6) / (molar_mass);
}
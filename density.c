#include "density.h"

// kiszámolja a számsűrűséget (1/A^3)
double calculate_number_density(double rho, double molar_mass){
	return (rho * 0.6) / (molar_mass);
}
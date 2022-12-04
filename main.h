#pragma once
#include "matrix.h"
#include "stdbool.h"

typedef struct {
	double rho;
	double molar_mass;
	double dq;
	double min;
	double max;
}config;

config read_config(const char* config_path);

bool lazy_equal(const double a, const double b);

bool is_zero(const double a);

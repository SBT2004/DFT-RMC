// (C) Socz� B�lint
#pragma once
#include "matrix.h"
#include "stdbool.h"

// A program konfigur�ci�s adatait �rja le, f�jlb�l olvassuk fel
typedef struct {
	double rho;
	double molar_mass;
	double dq;
	double min;
	double max;
} config;

config read_config(const char* config_path);

void validate_config(config cfg);

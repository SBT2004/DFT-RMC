// (C) Soczó Bálint
#pragma once
#include "matrix.h"
#include "stdbool.h"

// A program konfigurációs adatait írja le, fájlból olvassuk fel
typedef struct {
	double rho;
	double molar_mass;
	double dq;
	double min;
	double max;
} config;

config read_config(const char* config_path);

void validate_config(config cfg);

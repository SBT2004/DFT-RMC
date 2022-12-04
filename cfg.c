#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "mystring.h"
#include "common.h"

#pragma warning(disable:4996)

// 
config read_config(const char* config_path) {
	FILE* fp = fopen(config_path, "r");
	char row[400];
	char* key;
	char* value_string;
	config config = { 0 };

	while (fgets(row, 399, fp) != NULL) {
		const char* delim = "=";
		key = strtok(row, delim);
		trim(key);
		string_tolower(key);

		value_string = strtok(NULL, delim);
		trim(value_string);
		double value = strtod(value_string, NULL);

		if (equal_string(key,"m"))
		{
			config.molar_mass = value;
		}
		else if (equal_string(key, "density"))
		{
			config.rho = value;
		}
		else if (equal_string(key, "min"))
		{
			config.min = value;
		}
		else if (equal_string(key, "max"))
		{
			config.max = value;
		}
		else if (equal_string(key, "dq"))
		{
			config.dq = value;
		}
	}
	return config;
}

bool lazy_equal(const double a, const double b) {
	const double myepsilon = DBL_MIN * 10.0;
	return fabs(a - b) <= myepsilon;
}

bool is_zero(const double a) {
	return lazy_equal(a, 0.0);
}

void validate_config(config cfg) {
	if (is_zero(cfg.dq))
	{
		printf("Config hiba:dq nem lehet 0");
		exit(config_error);
	}
	if (is_zero(cfg.max))
	{
		printf("Config hiba:a taromany vege nem lehet 0");
		exit(config_error);
	}
	if (lazy_equal(cfg.min,cfg.max))
	{
		printf("Config hiba:a tartomany hossza ne legyen 0");
		exit(config_error);
	}
	if (is_zero(cfg.molar_mass))
	{
		printf("Config hiba:a molaris tomeg nem lehet 0");
		exit(config_error);
	}
	if (is_zero(cfg.rho))
	{
		printf("Config hiba:a suruseg nem lehet 0");
		exit(config_error);
	}
}
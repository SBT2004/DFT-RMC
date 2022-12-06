#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"
#include "common.h"
#include "mystring.h"

//usafe függvényeket használok
#pragma warning(disable:4996)

// beolvassa soronként a config file-t, amit az elérési úttal megadtunk,
// majd összetársítja a keyeket a megfelelő elemeivel a config structnak
config read_config(const char* config_path) {
	FILE* fp = fopen(config_path, "r");

	char row[400];
	const char* delim = "=";
	config config = { 0 };

	while (fgets(row, 399, fp) != NULL) {
		char* key = strtok(row, delim);
		trim(key);
		string_tolower(key);

		char* value_string = strtok(NULL, delim);
		trim(value_string);
		double value = strtod(value_string, NULL);

		//társítás
		if (equal_string(key, "m"))
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

// néhány elvárás validálása a configgal kapcsolatban
void validate_config(config cfg) {
	if (is_zero(cfg.dq))
	{
		printf("Config hiba: dq nem lehet 0");
		exit(config_error);
	}
	if (is_zero(cfg.max))
	{
		printf("Config hiba: a taromany vege nem lehet 0");
		exit(config_error);
	}
	if (lazy_equal(cfg.min, cfg.max))
	{
		printf("Config hiba: a tartomany hossza ne legyen 0");
		exit(config_error);
	}
	if (is_zero(cfg.molar_mass))
	{
		printf("Config hiba: a molaris tomeg nem lehet 0");
		exit(config_error);
	}
	if (is_zero(cfg.rho))
	{
		printf("Config hiba: a suruseg nem lehet 0");
		exit(config_error);
	}
}
#include <string.h>
#include <ctype.h>
#include "mystring.h"

// Kisbetűssé alakítja a megadott stringet.
void string_tolower(char* str) {
	char* ptr = str;
	while (*ptr != 0)
	{
		*ptr = tolower(*ptr);
		ptr++;
	}
}

// Levágja a whitespace-eket a string két végén.
void trim(char* str)
{
	//Levágja az elejéről a whitespace-eket
	while (isspace(*str))
	{
		str++;
	}

	// ha a sor nem üres, csak akkor fusson le hátsó trimmelés
	if (*str != 0) {
		//Levágja az végéről a whitespace-eket
		char* end = str + strlen(str) - 1;
		while (end >= str && isspace(*end))
		{
			end--;
		}
		*(end + 1) = '\0';
	}
}

// Összehasonlít két stringet, és true-val tér vissza, ha
// (case sensitive módon) azonosak.
bool equal_string(const char* a, const char* b)
{
	return strcmp(a, b) == 0;
}
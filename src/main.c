#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"

int main()
{
	string_t* string = string_t_create("Hello World\0");
	string_t* string2 = string_t_create("Hi there");

	string_t_reverse(string);

	printf("first string reversed: %s\n", string_t_getstring(string));
	printf("second string: %s\n", string_t_getstring(string2));

	string_t_copy(string, string2);

	printf("second string coppied to first: %s\n",string_t_getstring(string));

	string_t_free(string);
	string_t_free(string2);

	free(string);
	free(string2);
	return 0;
}

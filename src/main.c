#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"

int main()
{
	string_t* string = string_t_create("Hello World\0");

	printf("%s", string_t_getstring(string));

	string_t_free(string);
	free(string);
	return 0;
}

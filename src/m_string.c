#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"
#include <stdbool.h>

string_t* string_t_create_s(const char* str, size_t size)
{
	string_t* string = (string_t*)malloc(sizeof(string_t));
	string->string = (char*) malloc(size);
	string->size = size;
	//printf("Size is %i", string_t_length(string));
	for(int i = 0; i < string_t_length(string); i++)
	{
		string->string[i] = str[i];
	}
	return string;
}

void string_t_free(string_t* p)
{
	free(p->string);
}

int string_t_length(string_t* s)
{
	return (int)s->size/sizeof(char);
}

void string_t_copy(string_t* a, string_t* b)
{
	a->string = (char*)realloc(a->string,b->size);
	a->size = b->size;
	for(int i = 0; i < string_t_length(b); i++)
	{
		a->string[i] = b->string[i];
	}
}

string_t* string_t_makecopy(string_t* s)
{
	return string_t_create_s(s->string,s->size);
}

const char* string_t_getstring(string_t* s)
{
	return s->string;
}

string_t* string_t_create(const char* s)
{
	bool endOfString = false;
	int charCounter = 0;

	while(!endOfString)
	{
		if(s[charCounter] == '\0')
		{
			charCounter++;
			endOfString = true;
		}
		else
		{
			charCounter++;
		}
	}

	//printf("%i",charCounter);
	return string_t_create_s(s, charCounter * sizeof(char));
}

#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"
#include <stdbool.h>
#include <string.h>

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
	free(p);
}

int string_t_length(string_t* s)
{
	return (int)s->size/sizeof(char);
}

void string_t_copy(string_t* a, string_t* b)
{
	a->string = (char*)realloc(a->string,b->size);
	a->size = b->size;
	memcpy(a->string,b->string,b->size);
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

void string_t_reverse(string_t* s)
{
	//printf("We are reversing");
	int length = string_t_length(s);

	for(int i = 0; i < length-2; i++)
	{
		int invert = length-2-i;
		if(i == invert || i > invert)
		{
			break;
		}
		char a = s->string[i];
		s->string[i] = s->string[invert];
		s->string[invert] = a;
	}
	//printf("%s", s->string);
}

bool string_t_equals(string_t* a, string_t* b)
{
	if(a->size != b->size)
		return false;

	for(int i = 0; i < string_t_length(a); i++)
	{
		if(a->string[i] != b->string[i])
		{
			return false;
		}
	}

	return true;
}

void string_t_edit(string_t* s, const char* b)
{
	string_t* nstring = string_t_create(b);
	string_t_copy(s,nstring);
	string_t_free(nstring);
}

void string_t_concat(string_t* a, string_t* b)
{
	char* temp = (char*)malloc(a->size + b->size - 1);
	memcpy(temp, a->string, a->size - 1 * sizeof(char));
	memcpy(temp + (a->size - 1), b->string, b->size);
	string_t_edit(a,temp);
	free(temp);
}

void string_t_addconcat(string_t* a, const char* b)
{
	string_t* temp = string_t_create(b);
	string_t_concat(a,temp);
	string_t_free(temp);
}

#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"
#include <stdbool.h>
#include <string.h>

/*
 * Author: TheQuantumBlaze
 * Purpose: To provide strings in C
 * Language:  C
 *     
 */


/*
 * Function: string_t_create_s
 *
 * Returns: a pointer to a string_t* allocated with malloc
 *
 * Str: A char array to create the string from
 * Size: The size of Str
 *
 * This is the safe function and only moves size number of bytes from str to the string
 */
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

/*
 * Function: string_t_free
 *
 * Returns: Void 
 *
 * P: A string pointer that you want to free
 *
 * This free's the memory used within the string and free's the string pointer it self 
 */
void string_t_free(string_t* p)
{
	free(p->string);
	free(p);
}

/*
 * Function: string_t_length 
 *
 * Returns: Int : the number of char's contained in the string
 *
 * S: A pointer to the string you want to get the length of 
 *
 * Gets the length of a string
 */
int string_t_length(string_t* s)
{
	return (int)s->size/sizeof(char);
}

/*
 * Function: string_t_copy 
 *
 * Returns: void
 *
 * A: The destination string
 * B: The source string
 *
 * This function copies the string of b into a
 */
void string_t_copy(string_t* a, string_t* b)
{
	a->string = (char*)realloc(a->string,b->size);
	a->size = b->size;
	memcpy(a->string,b->string,b->size);
}

/*
 * Function: string_t_makecopy 
 *
 * Returns: string_t
 *
 * S: The string you want to copy 
 * 
 * Makes a copy of a string and returns a pointer of the copy
 */
string_t* string_t_makecopy(string_t* s)
{
	return string_t_create_s(s->string,s->size);
}

/*
 * Function: string_t_getstring 
 *
 * Returns: const char*
 *
 * S: The string you want to get the const char* for 
 *
 * This function returns a const char* so that this string class can interface with stdio
 * This function is not needed as you can use s->string but it is included for convience
 */
const char* string_t_getstring(string_t* s)
{
	return s->string;
}

/*
 * Function: string_t_create 
 *
 * Returns: string_t*
 *
 * S: The chars you want to convert into a string 
 *
 * This is the unsafe method for creating a string_t
 * This method looks for a null termination within the char*
 * This means that a buffer overflow is possible with this
 * This does allow you to create strings without knowing its length
 */
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

/*
 * Function: string_t_reverse 
 *
 * Returns: void
 *
 * S: The string you want to reverse 
 *
 * This method reverses a string and stores the data back in the provided string
 */
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

/*
 * Function: string_t_equals 
 *
 * Returns: bool
 *
 * A: The first string you want to evaluate 
 * B: The second string you want to evaluate
 *
 * This function checks two strings to see if they are the same and returns true or false
 */
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

/*
 * Function: string_t_edit 
 *
 * Returns: Void
 *
 * S: The string you want to edit 
 * B: A char* to the string you want to change S to
 *
 * This function changes an already created string from a char*
 * This is not concatanation and the char* replaces the data in S
 */
void string_t_edit(string_t* s, const char* b)
{
	string_t* nstring = string_t_create(b);
	string_t_copy(s,nstring);
	string_t_free(nstring);
}

/*
 * Function: string_t_concat 
 *
 * Returns: void
 *
 * A: The first string and the place that the concatanation is stored 
 * B: The string you want to concat A with
 * 
 * This function concats 2 strings and stores them into A
 */
void string_t_concat(string_t* a, string_t* b)
{
	char* temp = (char*)malloc(a->size + b->size - 1);
	memcpy(temp, a->string, a->size - 1 * sizeof(char));
	memcpy(temp + (a->size - 1), b->string, b->size);
	string_t_edit(a,temp);
	free(temp);
}

/*
 * Function: string_t_addconcat 
 *
 * Returns: void
 *
 * A: The first string you want to concat and the store for the concat 
 * B: A char* you want to concat a string with
 *
 * This method is a helper function which allows you to concat a string with a char*
 */
void string_t_addconcat(string_t* a, const char* b)
{
	string_t* temp = string_t_create(b);
	string_t_concat(a,temp);
	string_t_free(temp);
}

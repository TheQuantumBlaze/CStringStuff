
#ifndef M_STRING_H
#define M_STRING_H

#include <stdbool.h>

typedef struct
{
	char* string;
	size_t size;
} string_t;

string_t* string_t_create_s(const char*, size_t);
void string_t_free(string_t*);
int string_t_length(string_t*);
void string_t_copy(string_t*, string_t*);
string_t* string_t_makecopy(string_t*);
const char* string_t_getstring(string_t*);
string_t* string_t_create(const char*);
void string_t_reverse(string_t*);
bool string_t_equals(string_t*, string_t*);
void string_t_edit(string_t*, const char*);
void string_t_concat(string_t*, string_t*);
void string_t_addconcat(string_t*, const char*);
#endif

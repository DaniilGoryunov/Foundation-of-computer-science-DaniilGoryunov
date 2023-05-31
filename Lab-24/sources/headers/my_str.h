#pragma once
#include <stdlib.h>

#define Min_Cap_Str 20

typedef struct 
{
    char* buffer;
    int capacity, size;
} my_str;
my_str init();
void add_char(my_str* s, char value);
void destroy_str(my_str* s, char value);

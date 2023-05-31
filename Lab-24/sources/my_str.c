#include <headers/my_str.h>

my_str init(){
    my_str s;
    s.buffer = malloc(sizeof(char) * Min_Cap_Str);
    s.capacity = Min_Cap_Str;
    s.size = 0;
    return s;
}

static void increase_buffer (my_str* s){
    if (s->capacity < s->size * 2){
        s->buffer = realloc(s->buffer, sizeof(char) * s->capacity * 2);
    }
}

void add_char(my_str* s, char value){
    increase_buffer(s);
    s->buffer[s->size] = value;
    s->size++;
}

void destroy_str(my_str* s){
    free(s->buffer);
}
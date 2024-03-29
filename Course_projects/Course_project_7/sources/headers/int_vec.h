#pragma once
#include <stdbool.h>

typedef struct {
    int * buf;
    int size;
    int cap;
    int head;
} int_vec;

int_vec init(void);
void destroy(int_vec *v);
bool push_back(int_vec *v, int val);
bool push_front(int_vec *v, int val);
int pop_back(int_vec *v);
int pop_front(int_vec *v);
void vectorResize(int_vec *v, size_t newSize);
void vectorInsert(int_vec *v, size_t index, int value);
bool is_empty(int_vec *v);
int get_size(int_vec *v);
bool set_size(int_vec *v, int new_size);
int get_el(int_vec *v, int idx);
void set_el(int_vec *v, int idx, int val);

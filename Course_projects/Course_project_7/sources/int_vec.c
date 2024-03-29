#include <stdlib.h>
#include "headers/int_vec.h"
#define MIN_CAP 32

static bool increase_buf(int_vec *v){
    if (v->size * 2 <= v->cap){
        return true;
    }
    int new_cap = 2 * v->cap;
    if (new_cap < MIN_CAP){
        new_cap = MIN_CAP;
    }
    int *tmp = realloc(v->buf, new_cap * sizeof(int));
    if (tmp == NULL){
        return false;
    }
    v->buf = tmp;
    v->cap = new_cap;
    return true;
}

static void decrease_buf(int_vec *v){
    if (v->size >= v->cap / 4){
        return;
    }
    int new_cap = v->cap / 2;
    if (new_cap < MIN_CAP){
        new_cap = MIN_CAP;
    }
    if (new_cap < v->cap){
        int* tmp = realloc(v->buf, new_cap * sizeof(int));
        if (tmp == NULL){
            return;
        }
        // обработка всех случаев располажения элементов в буфере
        if (v->head > new_cap - 1) {
            for (int i = v->head; i < v->cap; i++){
                v->buf[new_cap-(v->cap - i)] = v->buf[i];
            }
            v->head = v->cap - new_cap;
        } else if (v->head + v->size > new_cap - 1){
            for (int i = new_cap; i < v->head + v->size; i++){
                v->buf[i % new_cap] = v->buf[i];
            }
        }
        v->buf = tmp;
        v->cap = new_cap;
    }
}

bool set_size(int_vec *v, int new_size){
    if (new_size <= v->cap){
        v->size = new_size;
        decrease_buf(v);
        return true;
    }
    if (new_size == v->size + 1){
        if (!increase_buf(v)){
            return false;
        }
        v->size = new_size;
        return true;
    }
    // больше чем 1 элемент, increase не гарантирует, что всё влезет
    int new_cap = new_size;
    int *tmp = realloc(v->buf, new_cap * sizeof(int));
    if (tmp == NULL){
        return false;
    }
    v->buf = tmp;
    if (v->head + v->size > v->cap){
        int old_cap = v->cap;
        for (int i = old_cap; i >= v->head; i--){
            v->buf[i + new_cap - old_cap] = v->buf[i];
        }
        v->head += new_cap - old_cap;
    }
    v->size = new_size;
    v->cap = new_cap;
    return true;
}

void vectorResize(int_vec *v, size_t newSize) {
    v->size = newSize;
    if (newSize > v->cap) {
        v->cap = newSize;
        v->buf = realloc(v->buf, v->cap * sizeof(int));
    }
}

void vectorInsert(int_vec *v, size_t index, int value) {
    vectorResize(v, v->size + 1);
    for (size_t i = (v->size - 1);i > index;i--) {
        v->buf[i] = v->buf[i - 1];
    }
    v->buf[index] = value;
}

int_vec init(void){
    int_vec v;
    v.cap = MIN_CAP;
    v.head = 0;
    v.size = 0;
    v.buf = malloc(v.cap * sizeof(int));
    return v;
}

void destroy(int_vec* v){
    v->size = 0;
    v->head = -1;
    free(v->buf);
}

bool push_back(int_vec *v, int val){
    if (!increase_buf(v)){
        return false;
    }
    v->buf[(v->head + v->size) % v->cap] = val;
    v->size++;
    return true;
}

bool push_front(int_vec *v, int val){
    if (!increase_buf(v)){
        return false;
    }
    v->buf[(v->head - 1 + v->cap) % v->cap] = val;
    v->head = (v->head - 1 + v->cap) % v->cap;
    v->size++;
    return true;
}

int pop_back(int_vec *v){
    int res = v->buf[(v->head + v->size - 1) % v->cap];
    v->size--;
    decrease_buf(v);
    return res;
}

int pop_front(int_vec *v){
    int res = v->buf[v->head];
    v->size--;
    v->head = (v->head + 1) % v->cap;
    decrease_buf(v);
    return res;
}

bool is_empty(int_vec *v){
    return v->size == 0;
}

int get_size(int_vec *v){
    return v->size;
}

int get_el(int_vec *v, int idx){
    return v->buf[(v->head + idx) % v->cap];
}

void set_el(int_vec *v, int idx, int val){
    v->buf[(v->head + idx) % v->cap] = val;
}

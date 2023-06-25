#include "headers/tree_stack.h"
#include <stdlib.h>
#include <stdbool.h>

void ts_init(tree_stack *s){
    s->first = NULL;
}

bool ts_is_empty(tree_stack *s){
    if (s->first == NULL){
        return true;
    }
    return false;
}

bool ts_push(tree_stack *s, tree val){
    ts_node *new_node = malloc(sizeof(ts_node));
    if (new_node == NULL)
        return false;
    new_node->val = val;
    new_node->next = s->first;
    s->first = new_node;
    return true;
}

tree ts_pop(tree_stack *s){
    ts_node *old = s->first;
    s->first = old->next;
    tree v = old->val;
    free(old);
    return v;
}

void ts_destroy(tree_stack *s){
    ts_node *cur = s->first;
    while (cur != NULL){
        ts_node *next = cur->next;
        free(cur);
        cur = next;
    }
    s->first = NULL;
}

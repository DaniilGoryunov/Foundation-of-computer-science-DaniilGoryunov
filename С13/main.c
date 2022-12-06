#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define CONSONANTS (1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') | 1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') | 1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') | 1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a'))

typedef enum {
    INSIDE,
    OUTSIDE
} State;

State get_state(char s) {
    return (s == ' ') || (s == '\n') || (s == ',') || (s == EOF) ? OUTSIDE : INSIDE;
}

bool common_cons(void) {
    State state;
    unsigned int pool_un=0;
    for (char s = getchar(); s != EOF; s = getchar()) {
        state = get_state(s);
        switch (state) {
            case INSIDE:
                if (CONSONANTS & 1u << (s - 'a')) {
                    if (pool_un & 1u << (s - 'a')){
                        return true;
                    } else{
                        pool_un=pool_un|1u << (s-'a');
                    }
                }
                break;
            case OUTSIDE:
                pool_un=0;
                break;
        }
    }
    return false;
}


int main(void) {
    printf("%d\n", common_cons());
    return 0;
}


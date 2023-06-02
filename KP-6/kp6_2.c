#include <stdio.h>
#include "fields.h"
#include <stdbool.h>
#include <string.h>

char string_to_int(char* str){
    int intic = 0;
    for (int i = 0; i < (strlen(str)/sizeof(char)); ++i){
        intic = str[i] - '0' + intic * 10;
    }
    return intic;
}

bool is_need_to_upgrade(comp c, int n1, int n2){
    return (c.cores < n1 || c.memory < n2);
}


int main(int argc, char* argv[]){
    if (argc < 2 || argc == 4 || argc == 3 || argc > 6){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    char* n1 = "4";
    char* n2 = "4";
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    if (argc > 2){
        if (strcmp("-p", argv[2]) == 0){
            n1 = argv[3];
            n2 = argv[4];
        }
    }
    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    comp c;
    fseek(file, sizeof(int), SEEK_SET);
    for (int i = 0; i < n - 1; i++) {
        if (fread(&c, sizeof(comp), 1, file) != 1) {
            fprintf(stderr, "Read elem error!\n");
            return 1;
        }
        if (is_need_to_upgrade(c, string_to_int(n1), string_to_int(n2)))
            printf("%s\n", c.surname);
    }
    return 0;
}

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

int comps_powerful(comp c){
    int n = 0;
    if (c.cores > 4) n++;
    if (c.memory_size > 256) n++;
    if (c.memory > 4) n++;
    if (c.vinchesters > 4) n++;
    return n;
}


int main(int argc, char* argv[]){
    if (argc!=4){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    int n1;
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    if (strcmp("-p", argv[2]) == 0){
        n1 = string_to_int(argv[3]);
    } else{ 
        fprintf(stderr, "Write -p parameter!\n");
        return 3;
    }
    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    comp c;
    int power[n], min = __INT_MAX__;
    fseek(file, sizeof(int), SEEK_SET);
    for (int i = 0; i < n; i++) {
        if (fread(&c, sizeof(comp), 1, file) != 1) {
            fprintf(stderr, "Read elem error!\n");
            return 1;
        }
        power[i] = comps_powerful(c);
        if (power[i] < min)
            min = comps_powerful(c);
    }
    int cnt = 0;
    while (n1 > cnt){
        fseek(file, sizeof(int), SEEK_SET);
        for (int i = 0; i < n; i++) {
            fread(&c, sizeof(comp), 1, file);
            if (power[i] == min) {
                cnt++;
                printf("%s ", c.surname);
            }
        }
        min++;
    }
    return 0;
}

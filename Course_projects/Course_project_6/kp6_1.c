#include <stdio.h>
#include <stdlib.h>
#include "fields.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 2;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create output file!\n");
        return 3;
    }
    int chr;
    do {
        chr = fgetc(input);
        if (chr == EOF){
            fprintf(stderr, "Headers read error!\n");
            return 4;
        }
    } while (chr != '\n');
    comp c;
    int counter = 0;
    fseek(output, sizeof(int), SEEK_SET); // в бинарном файле оставили место для каунтера
    while (fscanf(input, "%[^;];%[^;];%d;%d;%[^;];%d;%d;%[^;];\n", c.surname, c.proc, &c.memory_size, &c.cores, c.video_type, &c.memory, &c.vinchesters, c.os_name) == 8){
        if (fwrite(&c, sizeof(comp), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 5;
        }
        counter++;
    }
    fseek(output, 0, SEEK_SET);     // pointer to top of file
    if (fwrite(&counter, sizeof(int), 1, output) != 1) {
        fprintf(stderr, "Write error!\n");
        return 1;
    }
    printf("%d lines are written\n", counter);
    fclose(input);
    fclose(output);

    return 0;
}   

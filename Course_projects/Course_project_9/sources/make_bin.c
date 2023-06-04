#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        fprintf(stderr, "Wrong number of args!\n");
        return 2;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output1 = fopen(argv[2], "wb");
    FILE* output2 = fopen(argv[3], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open input file!\n");
        return 1;
    }
    if (output1 == NULL || output2 == NULL){
        fprintf(stderr, "Can't create output file!\n");
        return 3;
    }
    char line[99];
    int counter = 0, key;
    while (fscanf(input, "%[^;];%d\n", line, &key) == 2){
        if (fwrite(line, sizeof(line), 1, output1) != 1){
            fprintf(stderr, "Write error in 1st file!\n");
            return 5;
        }
        if (fwrite(&key, sizeof(key), 1, output2) != 1){
            fprintf(stderr, "Write error in 2nd file!\n");
            return 5;
        }
        counter++;
    }
    printf("%d lines are written\n", counter);
    fclose(input);
    fclose(output1);
    fclose(output2);
    return 0;
}

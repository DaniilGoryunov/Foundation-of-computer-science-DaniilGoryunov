#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void shekerSort(int *mass, int count, FILE* f){
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    bool is_moved = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && is_moved > 0){
        is_moved = 0;
        char tmp_str[99], tmp1_str[99];
        for (int i = left; i<right; i++){  //двигаемся слева направо
            fseek(f, sizeof(char[99])*i, SEEK_SET);
            fread(tmp_str, sizeof(tmp_str), 1, f);
            if (mass[i]>mass[i + 1]){ // если следующий элемент меньше текущего,  
                int t = mass[i];                // меняем их местами
                fseek(f, sizeof(char[99])*(i+1), SEEK_SET);
                fread(tmp1_str, sizeof(tmp1_str), 1, f);
                mass[i] = mass[i + 1];
                fseek(f, sizeof(char[99])*i, SEEK_SET);
                fwrite(tmp1_str, sizeof(tmp1_str), 1, f);
                fseek(f, sizeof(char[99])*(i+1), SEEK_SET);
                fwrite(tmp_str, sizeof(tmp_str), 1, f);
                mass[i + 1] = t;
                is_moved = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i>left; i--){  //двигаемся справа налево
            fseek(f, sizeof(char[99])*i, SEEK_SET);
            fread(tmp_str, sizeof(tmp_str), 1, f);
            if (mass[i - 1]>mass[i]){ // если предыдущий элемент больше текущего, 
                fseek(f, sizeof(char[99])*(i-1), SEEK_SET);
                fread(tmp1_str, sizeof(tmp1_str), 1, f);          
                int t = mass[i]; // меняем их местами
                mass[i] = mass[i - 1];
                fseek(f, sizeof(char[99])*i, SEEK_SET);
                fwrite(tmp1_str, sizeof(tmp1_str), 1, f);
                fseek(f, sizeof(char[99])*(i-1), SEEK_SET);
                fwrite(tmp_str, sizeof(tmp_str), 1, f);
                mass[i - 1] = t;
                is_moved = 1;    // перемещения в этом цикле были
            }
        }
    left++; // сдвигаем левую границу на следующий элемент
    }
}

bool read_keys(FILE* f, int n, int* k){
    for (int i = 0; i < n; i++){
        if (fread(&k[i], sizeof(int),1, f) != 1)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]){
    if (argc!=3){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    int n;
    FILE* ascii = fopen(argv[1], "rb");
    if (ascii == NULL){
        fprintf(stderr, "Can't open 1st file!\n");
        return 1;
    }
    FILE* keys = fopen(argv[2], "rb");
    if (keys == NULL){
        fprintf(stderr, "Can't open 2nd file!\n");
        return 1;
    }
    if (fread(&n, sizeof(int), 1, keys) != 1){
        fprintf(stderr, "Error number of keys");
    }
    int key[n];
    if(!read_keys(keys, n, key))
        fprintf(stderr, "Read keys error");
    shekerSort(key, n, ascii);
    return 0;
}

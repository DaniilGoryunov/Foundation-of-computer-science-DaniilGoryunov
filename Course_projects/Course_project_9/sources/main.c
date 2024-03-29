//шейкер сортировка; ключ - смешанный; хранятся отдельно
#include "headers/key.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    key k;
    char val[99];
} map;

bool read_keys(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].k, sizeof(key), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

bool read_art(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].val, sizeof(char[99]), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

void cocktail_sort(int table_size, map* m){
    int left_border = 0, right_border = table_size - 1;
    map tmp;
    while(left_border <= right_border){
        for (int i = left_border; i < right_border; ++i){
            if (keycmp(m[i].k, m[i + 1].k) > 0){
                tmp = m[i];
                m[i] = m[i + 1];
                m[i + 1] = tmp;
            }
        }
        --right_border;
        for (int i = right_border; i > left_border; --i){
            if (keycmp(m[i].k, m[i - 1].k) < 0){
                tmp = m[i];
                m[i] = m[i - 1];
                m[i - 1] = tmp;
            }
        }
        ++left_border;
    }
}

// void _print_art(FILE* art) {
//     fseek(art, 0, SEEK_SET);
//     char line[99];
//     while (fread(line, sizeof(line), 1, art) == 1) {
//         printf("%s\n", line);
//     }
// }

void print_art(int n, map* m) {
    for (int i = 0; i < n; i++) {
        printf("%d%c ", m[i].k.num, m[i].k.letter);
        printf("%s\n", m[i].val);
    }
}

key get_key() {
    key k;
    scanf("%d%c", &k.num, &k.letter);
    return k;
}

int binary_search(key k, int n, map* m) {
    int mid = n / 2;
    int low = 0, high = n - 1;
    while (keycmp(m[mid].k, k) != 0 && low <= high) {
        if (keycmp(k, m[mid].k) > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }
    if (low > high) {
        return -1;
    } else {
        return mid;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* art = fopen(argv[1], "rb");
    if (art == NULL) {
        fprintf(stderr, "Can't open the second file!");
        return 2;
    }
    FILE* keys = fopen(argv[2], "rb");
    if (keys == NULL) {
        fprintf(stderr, "Can't open the first file!");
        return 2;
    }
    int n;
    if (fread(&n, sizeof(int), 1, keys) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 3;
    }
    map m[n];
    if (!read_keys(keys, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    if (!read_art(art, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    fclose(keys);
    fclose(art);
    print_art(n, m);
    cocktail_sort(n, m);
    printf("\n");
    print_art(n, m);
    while (true) {
        printf("Enter key:\n");
        key user = get_key();
        int idx = binary_search(user, n, m);
        if (idx < 0) {
            printf("Key not found!\n");
        } else {
            printf("%s\n", m[idx].val);
        }
    }

    return 0;
}

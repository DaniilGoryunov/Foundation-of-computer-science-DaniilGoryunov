#include <stdio.h>
#include <ctype.h>
#include "headers/int_vec.h"
#include "headers/matrix.h"

int matrixGet(matrix *matrix, size_t i, size_t j) {
    int result = 0;
    int curRowPiInd = matrix->CIP->buf[i];
    int nextRowPiInd;
    if (i == (matrix->lines - 1)) {
        nextRowPiInd = (get_size(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->buf[i + 1];
    }
    for (;curRowPiInd != nextRowPiInd;curRowPiInd++) {
        if ((size_t)matrix->PI->buf[curRowPiInd] == j)
            result = matrix->YE->buf[curRowPiInd];
    }
    return result;
}

void matrixSet(matrix *matrix, size_t i, size_t j, int value) {
    size_t n = matrix->lines;
    int curRowPiInd = matrix->CIP->buf[i];
    int nextRowPiInd;
    if (i == (n - 1)) {
        nextRowPiInd = (get_size(matrix->PI) - 1);
    } else {
        nextRowPiInd = matrix->CIP->buf[i + 1];
    }
    // Row is zero
    if (curRowPiInd == nextRowPiInd) {
        vectorInsert(matrix->PI, curRowPiInd, j);
        vectorInsert(matrix->YE, curRowPiInd, value);
        for (size_t k = i + 1;k < n;k++) matrix->CIP->buf[k]++;
    } else {
        while (j > (size_t)matrix->PI->buf[curRowPiInd] && curRowPiInd != nextRowPiInd) {
            curRowPiInd++;
        }
        if (j == (size_t)matrix->PI->buf[curRowPiInd] && curRowPiInd != nextRowPiInd) {
            if (value == 0) {
                matrix->PI->size--;
                matrix->YE->size--;
                for (size_t k = curRowPiInd;k < matrix->PI->size;k++) {
                    matrix->PI->buf[k] = matrix->PI->buf[k + 1];
                    matrix->YE->buf[k] = matrix->YE->buf[k + 1];
                }
                for (size_t k = i + 1;k < matrix->lines;k++) matrix->CIP->buf[k]--;
            } else {
                matrix->YE->buf[curRowPiInd] = value;
            }
        }
        else {
            vectorInsert(matrix->PI, curRowPiInd, j);
            vectorInsert(matrix->YE, curRowPiInd, value);
            for (size_t k = i + 1;k < n;k++) matrix->CIP->buf[k]++;
        }
    }
}

void input_matr(matrix* m){
    m->width = 0;
    m->lines = 0;
    int c = getchar();
    int num = 0, column = 0, not_zeros = 0;
    bool is_negative = false;
    while (c != EOF){
        if (c == ' '){
            if (num != 0){
                if (is_negative) {
                    num *= -1;
                }
                push_back(m->YE, num);
                push_back(m->PI, column);
                not_zeros++;
            }
            // как-то надо определить первый элекмент в линии: длина всего вектора PI - количество элементов в текущей строке
            column++;
            num = 0;
            is_negative = false;
        } else if (c == '\n' || c == EOF) {
            if (num != 0){
                if (is_negative) {
                    num *= -1;
                }
                push_back(m->YE, num);
                push_back(m->PI, column);
                not_zeros++;
            }
            push_back(m->CIP, get_size(m->PI) - not_zeros);
            not_zeros = 0;
            column++;
            if (column > m->width) {
                m->width = column;
            }
            column = 0;
            num = 0;
            is_negative = false;
            m->lines++;
        } else if (c == '-') {
            is_negative = true;
        } else if (!isdigit(c)){
            fprintf(stderr, "Not number was inputed!\n");
            m->width = -1;
            return;
        } else {
            num *= 10;
            num += c - '0';
        }
        c = getchar();
    }
}

void print_zeros(int n){
    if (n == 0){
        return;
    }
    for (int i = 0; i < n; i++){
        printf("0 ");
    }
}

void print_matr(matrix m){
    int idx_line = 0, column = 0;
    for (int i = 0; i < get_size(m.PI); i++){
        // printf("    DEBUG: i = %d  idx_line = %d    ", i, idx_line);
        if (idx_line < m.lines)
            if (i == get_el(m.CIP, idx_line)){
                if (column != m.width && i != 0){
                    print_zeros(m.width - column);
                }
                printf("\n");
                idx_line++;
                if (idx_line < m.lines)
                    if (get_el(m.CIP, idx_line - 1) == get_el(m.CIP, idx_line)) {
                        print_zeros(m.width);
                        printf("\n");
                        idx_line++;
                    }
                column = 0;
            } 
        if (get_el(m.PI, i) > column) {
            print_zeros(get_el(m.PI, i) - column);
            column = get_el(m.PI, i);
        }
        printf("%d ", get_el(m.YE, i));
        column++;
    }
    print_zeros(m.width - column);
    printf("\n");
    for (int i = 0; i < m.lines - idx_line; i++) {
        print_zeros(m.width);
        printf("\n");
    }
    printf("\n");
    // printf("width: %d\n", width);
}

// return el's idx in PI or YE
int abs_max(matrix m) {
    int max = 0, idx_max, preidx_max;
    bool is_same_exist = false;
    for (int i = 0; i < get_size(m.YE); i++) {
        if (abs(get_el(m.YE, i)) > max) {
            max = abs(get_el(m.YE, i));
            idx_max = i;
            is_same_exist = false;
        } else if (abs(get_el(m.YE, i)) == max) {
            if (get_el(m.PI, i) > get_el(m.PI, idx_max)) {
                preidx_max = idx_max;
            } else {
                preidx_max = i;
            }
            idx_max = i;
            is_same_exist = true;
        }
    }
    if (is_same_exist) {
        return preidx_max;
    }
    return idx_max;
}

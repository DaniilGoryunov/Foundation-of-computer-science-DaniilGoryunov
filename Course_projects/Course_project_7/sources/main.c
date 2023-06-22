//Тип размещения: Три вектора. Вариант преобразования 2. Определить максимальный по модулю элемент матрицы и разделить на него все элементы столбца, в котором он находится. Если таких элементов несколько, обработать предпоследний столбец, содержащий такой элемент.
#include <stdio.h>
#include "headers/int_vec.h"
#include "headers/matrix.h"

void divide_column(matrix m, int column, int val) {
    for (int i = 0; i < get_size(m.PI); i++) {
        if (get_el(m.PI, i) == column) {
            set_el(m.YE, i, get_el(m.YE, i) / val);
        }
    }
}


int main(void){
    matrix m;
    int_vec CIP = init();
    int_vec PI = init();
    int_vec YE = init();
    m.CIP = &CIP;
    m.PI = &PI;
    m.YE = &YE;
    input_matr(&m);
    if (m.width == -1){
        return 1;
    }
    printf("CIP:\n");
    for (int i = 0; i < get_size(m.CIP); i++){
        printf("%d\n", get_el(&CIP, i));
    }
    printf("PI:\n");
    for (int i = 0; i < get_size(m.PI); i++){
        printf("%d\n", get_el(&PI, i));
    }
    printf("YE:\n");
    for (int i = 0; i < get_size(m.YE); i++){
        printf("%d\n", get_el(&YE, i));
    }

    printf("Matrix:\n");
    print_matr(m);    
    matrixSet(&m, 1, 1, 3);
    print_matr(m);   
    printf("\n");
    printf("%d\n", matrixGet(&m, 1, 2));
    matrixSet(&m, 1, 1, 3);
    int idx_max = abs_max(m);
    int max_column = get_el(m.PI, idx_max);
    divide_column(m, max_column, get_el(m.YE, idx_max));
    printf("Divided matrix:\n");
    print_matr(m);

    
    destroy(m.CIP);
    destroy(m.PI);
    destroy(m.YE);

    return 0;
}

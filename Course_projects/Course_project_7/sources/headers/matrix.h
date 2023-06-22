typedef struct {
    int_vec* CIP;   // idx of first el in PI and YE
    int_vec* PI;    // numbers of column
    int_vec* YE;    // numbers
    int width;  // number of columns
    int lines; 
} matrix;

int matrixGet(matrix *matrix, size_t i, size_t j);
void matrixSet(matrix *matrix, size_t i, size_t j, int value);
void input_matr(matrix* m);
void print_zeros(int n);
void print_matr(matrix m);
int abs(int a);
int abs_max(matrix m);

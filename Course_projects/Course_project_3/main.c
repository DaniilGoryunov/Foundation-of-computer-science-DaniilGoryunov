#include <stdio.h>
#include <float.h>
#include <math.h>

#define MAX_ITER 100
#define K 1

typedef struct {
    double sum;
    int iters_count;
} Taylor;

double epsilon(void) {
    double eps = 1.0;
    while (1.0+(eps/2.0)>1.0) {
        eps /= 2.0;
    }
    return eps;
}

Taylor taylor_log(double func_arg) {
    Taylor res;
    res.sum = 0.0;
    res.iters_count = 0;
    double term = log(2), x = func_arg;
    res.sum += term;
    for (int n = 1; (n < MAX_ITER && fabs(term) >= epsilon()); n++) {
        res.iters_count++;
        term = pow(-1, n-1)*(pow(x, n)/(n*pow(2, n)));
        if (res.sum + term == res.sum) break;
        res.sum += term;
    }
    return res;
}

void output(double a, double b, int n) {
    double step = (b - a) / n, x;
    printf("    x       log        taylor_log  i\n");
    for (int i = 0; i < n; i++) {
        x = a + i * step;
        printf("%.5lf %.10lf %.10lf %d \n", x, log(2+x), taylor_log(x).sum, taylor_log(x).iters_count);
    }
}

int main(void) {
    const double a = -1.0, b = 1.0;
    const int n = 30;
    output(a, b, n);
    return 0;
}

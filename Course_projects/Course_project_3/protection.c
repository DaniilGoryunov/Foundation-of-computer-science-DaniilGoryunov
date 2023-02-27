#include <stdio.h>
#include <math.h>

double min(double n1, double n2) {
    double copy,half=(n1+n2)/2;
    if (n1>n2){
        copy=n2;
        while (half!=n1){
            half=(n1+n2)/2;
            copy=n2;
            n2=half;
        }
    }
    else {
        copy=n1;
        while (half!=n1){
            half=(n1+n2)/2;
            copy=n2;
            n2=half;
        }
    }
    return copy;
}


int main(){
    double n1,n2;
    scanf("%lf %lf",&n1,&n2);
    printf("%22.20lf\n",min(n1,n2));
}


#include <stdio.h>
#include <math.h>

#define e  2.7182818284
 
double f(double x);

double f1(double x);

double f2(double x);

int main()
{
    int n=0;
    double a=1,b=3;
    double c,eps=0.00001;
    
    if(fabs(f(a)*f2(a))<fabs(f1(a)))
        c=a;
    else
        c=b;
    while (fabs(f(c))>=eps){
        c-=f(c)/f1(c);
        n++;
    }
    
    printf("c=%lf\n",c);
    printf("n=%d\n",n);
}

double f(double x)
{
    return   3*x-14+pow(e, x)-pow(e, -x);
}
 
double f1(double x)
{
    return  3+pow(e, x)-pow(e, -x) ;
}
 
double f2(double x)
{
    return pow(e, x)-pow(e, -x);
}
 


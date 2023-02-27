#include <stdio.h>

double two_sum (double t, double a, double b) {
  double s = a+b;
  double bs = s-a;
  double as = s-bs;
  t = (b-bs) + (a-as);
  return s;
}

int main(){
    int n;
    scanf ("%d", &n);
    double m[n];
    double s=0.0,c=0.0,t=0,summ=0;
    for(int i=0;i!=n;++i)
        scanf ("%lf", &m[i]);
    for (int i=1;i<=n;i+=2) {
        summ+=(m[i]+m[i+1]);
        s+=two_sum(t, m[i], m[i-1]);
        c+= t;
    }
    printf("%lf %lf\n",s+c,summ);
}

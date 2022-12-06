#include <stdio.h>
#include <stdlib.h>
 
#define MIN(a,b) ((a < b))? (a) : (b)

int MAX(a,b,c){
    if (a>b && a>c)
        return a;
    if(b>c && b>a)
        return b;
    if (c>b && c>a)
        return c;
    return 0;
}
 
int sign(int a)
{
    if (a > 0){
        return 1;
    }
 
    if (a == 0){
        return 0;
    }
 
    return -1;
}
 
int main()
{
    int i = 26;
    int j = 8;
    int l = -3;
 
    int ik = i, jk = j, lk = l;
 
    for (int k = 1; k <= 50; k++){
         
        i = ik;
        j = jk;
        l = lk;
 
        int ik = (MIN((i+j),(i+l))*(k+1))%30;
 
        int jk = (j+l*sign(j)%20)+(k*sign(i)%10);
 
        int lk = MAX(i*j, i*l,j*l)%30;
 
        printf("%d, %d, %d, %d\n", k, ik, jk, lk);
 
        if ((ik*ik+jk*jk>=25) && (ik*ik+jk*jk<=100)){
            printf("got it in %d = count of attempts, %d - x coord, %d - y coord, %d\n", k, ik, jk, lk);
            break;
        }
    }
 
    return 0;
}

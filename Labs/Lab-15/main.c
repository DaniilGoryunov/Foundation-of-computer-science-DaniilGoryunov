#include <stdio.h>
#include <limits.h>

void change(int n,int m[n][n],int indmin,int indmax);

void transform(int n, int m[n][n]);

void output(int n, int (*m)[n]);

int main (){
    int n;
    scanf ("%d", &n);
    int m[n][n];
    for(int i=0;i!=n;++i)
        for (int j = 0; j != n; ++j)
            scanf ("%d", &m[i][j]);
    putchar('\n');
    transform(n, m);
    output(n, m);
    return 0;
}

void change(int n,int m[n][n],int indmin,int indmax){
    for (int j = 0;j<n;j++){
        int k = m[indmin][j];
        m[indmin][j]=m[indmax][j];
        m[indmax][j]=k;
    }
}

void transform(int n, int m[n][n]){
    int max=INT_MIN, min=INT_MAX,indmax=0,indmin=0;
    for (int i = 0;i<n;i++){
        int prv=1;
        for (int(j)=0;j<n;j++)
            prv=prv*m[i][j];
        if (max<=prv){
            max=prv;
            indmax=i;}
        if (min>=prv){
            min=prv;
            indmin=i;}
    }
    change(n, m,indmin,indmax);
}

void output(int n, int (*m)[n]){
    for(int i = 0;i!=n;++i){
        putchar('\n');
        for (int j = 0; j != n; ++j){
            printf("%d ", m[i][j]);
        }
    }
}


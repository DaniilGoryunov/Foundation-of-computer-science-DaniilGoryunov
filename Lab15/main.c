#include <stdio.h>

int change(int n,int m[n][n],int indmin,int indmax){
    for (int(j)=0;j<n;j++){
        int(k)=m[indmin][j];
        m[indmin][j]=m[indmax][j];
        m[indmax][j]=k;
    }
    return m[n][n];
}

void maxminind(int n, int m[n][n]){
    int max, min,indmax,indmin,counter=0;
    for (int(i)=0;i<n;i++){
        int prv=1;
        for (int(j)=0;j<n;j++)
            prv=prv*m[i][j];
        if (counter==0){
            max=prv;
            indmax=i;
            min=prv;
            indmax=i;
            counter++;
        }else
            if (max<=prv){
                max=prv;
                indmax=i;}
            if (min>=prv){
                min=prv;
                indmin=i;}
    }
    m[n][n]=change(n, m,indmin,indmax);
    for(int i=0;i!=n;++i){
        counter=0;
        for (int j = 0; j != n; ++j){
            counter++;
            if (counter % n !=0)
                printf("%d ", m[i][j]);
            else
                printf("%d\n", m[i][j]);
        }
    }
}

int main (){
    int n;
    scanf ("%d", &n);
    int m[n][n];
    for(int i=0;i!=n;++i)
        for (int j = 0; j != n; ++j)
            scanf ("%d", &m[i][j]);
    putchar('\n');
    maxminind(n, m);
    return 0;
}



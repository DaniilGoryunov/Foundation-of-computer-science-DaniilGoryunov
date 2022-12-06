#include <stdio.h>
int main() {
    int n1,n2,n3,counter=0;
    char c;
    while ((c=getchar())!=EOF ){
        if (counter<2){
            if (counter%3==0)
                n1=c-'0';
            if (counter%3==1)
                n2=c-'0';
            if (counter%3==2)
                n3=c-'0';
            counter++;
        }
        else {
            n3=c-'0';
            if (n1==n2+n3)
                printf("%d\n",n1);
            n1=n2;
            n2=n3;
        }
    }
    return 0;
}


#include <stdio.h>
#include <stdbool.h>

int prov1(char c){
    char c1,c2,c3;
    c1=getchar();
    c2=getchar();
    c3=getchar();
    if (c1=='0' && c2=='0' && (c3=='1'||c3=='0'))
        return true;
    else return false;
}

int prov0(char c){
    char c1,c2,c3;
    c1=getchar();
    c2=getchar();
    c3=getchar();
    if ((c1=='1'||c1=='0')&&(c2=='0'||c2=='1')&&(c3=='0'||c3=='1'))
        return true;
    else return false;
}

int konets (int counter){
    char c;
    c=getchar();
    if (c==' '||c=='\n'||c==EOF)
        counter++;
    return counter;
}

int fp(int counter,char c){
    if (c=='1'){
        if (prov1(c))
            counter=konets(counter);
    }
    if (c=='0'){
        if (prov0(c))
            counter=konets(counter);
    }
    return counter;
}
    
int main(){
    int counter=0;
    char c;
    bool f;
    c=getchar();
    counter=fp(counter,c);
    f=false;
    while (c!=EOF){
        if (c==' '||c=='\n'){
            c=getchar();
            if (c=='1'){
                if (prov1(c)){
                    f=true;
                    c=getchar();
                    counter=konets(counter);
                }
            }
        }
        if (c=='0'){
            if (prov0(c)){
                f=true;
                c=getchar();
                counter=konets(counter);
            }
        }
        if (f==false)
            c=getchar();
        else f=false;
    }
    printf("\n%d\n",counter);
    return 0;
}

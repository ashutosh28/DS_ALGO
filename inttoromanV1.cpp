#include "array.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    int N;
    cin>>N;
    int X=N;
    int i,j=0;
    char *ROMAN = (char*) malloc(16*sizeof(char));
    if(X>4000) return 0;
    if(X<1) return 0;
    if(X>=1000) {
        int m = X/1000;
        for(i=0;i<m;++i) {
            ROMAN[j++]='M';
        }
        X = X % 1000;
    }
    if(X>=900) {
        ROMAN[j++]='C';ROMAN[j++]='M';
        X = X % 900;
    }else if (X >= 500) {
        int d = X/500;
        for(i=0;i<d;++i) {
            ROMAN[j++] = 'D';
        }
        X = X % 500;
    }
    if(X>=400) {
        ROMAN[j++]='C';ROMAN[j++]='D';
        X = X % 400;
    }else if (X >= 100) {
        int c = X/100;
        for(i=0;i<c;++i) {
            ROMAN[j++] = 'C';
        }
        X = X % 100;
    }
    if(X>=90) {
        ROMAN[j++]='X';ROMAN[j++]='C';
        X = X % 90;
    }else if (X>=50) {
        int e = X/50;
        for(i=0;i<e;++i) {
            ROMAN[j++]='L';
        }
        X = X % 50;
    }
    if(X>=40) {
        ROMAN[j++]='X';ROMAN[j++]='L';
        X = X % 40;
    }else if (X>=10) {
        int f = X/10;
        for(i=0;i<f;i++) {
            ROMAN[j++]='X';
        }
        X = X % 10;
    }
    if(X>=9) {
        ROMAN[j++]='I';ROMAN[j++]='X';
        X = X % 9;
    }else if (X>=5) {
        int g = X/5;
        for(i=0;i<g;++i) {
            ROMAN[j++]='V';
        }
        X = X % 5;
    }
    if(X>=4) {
        ROMAN[j++]='I';ROMAN[j++]='V';
        X = X % 4;
    }else if (X>=1) {
        int h = X/1;
        for(i=0;i<h;++i) {
            ROMAN[j++] = 'I';
        }
    }
    cout<<" ROMAN NUMBER : "<<ROMAN<<endl;
    return 0;
}


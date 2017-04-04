#include "array.h"
#include<stdlib.h>
#include<stdio.h>

int ** prettyPrint(int A,int *rows,int *cols);
int main() {
    int A,i,j,c,r;
    cin>>A;
    int **array = prettyPrint(A,&r,&c);
    for(i=0;i<r;++i) {
        for(j=0;j<c;++j) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int ** prettyPrint(int A,int *rows,int *cols) {
    *rows = 2*A-1;
    *cols = 2*A-1;
    int i,j;
    int **result = (int**) malloc(*rows *sizeof(int*));
    for(i=0;i<*cols;++i) {
        result[i] = (int*) malloc(*cols *sizeof(int));
    }
    for(i=0;i<A;++i) {
        int x = i;
        for(j=i;j<*cols-i;++j) {
            result[x][j] = A-i;
        }
        x = j-1;
        for(j=i;j<*rows-i;++j) {
            result[j][x] = A-i;
        }
        x = j-1;
        for(j=i;j<*cols-i;++j) {
            result[x][j] = A-i;
        }
        x = i;
        for(j=i;j<*rows-i;++j) {
            result[j][x] = A-i;
        }
    }
    return result;
}

#include "time.h"

int BitSwapReqd(int A, int B){
    int num=0;
    int c=A^B;
    while(c){
        if(c&1)num++;
        c=c>>1;
    }
    return num;
}
int main(){
    int A,B;
    scanf("%d%d",&A,&B);
    printf("%d required to convertor %d into %d",BitSwapReqd(A,B),A,B);
    return 0;
}

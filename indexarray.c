#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    int p,q=A[0];
    for(i=0;i<N;i++){
    
        p = A[A[i]]%N;;
        A[i] = A[i] + p*N;
        
    }
    for(i=0;i<N;i++){
        printf("%d ",A[i]/N);
    }
    printf("\n");
    return 0;
}

#include <iostream>
#include<cstdio>
int maxOnes(int *a, int n ) {
    /* N: size of the array 
     * The array is a row-major contiguous buffer of size N*N,
     * it's a 2-D array
     * */
     
        int i,j=0;
            int max_row_number;
             
                for(i=0;i<n;i++){
                            for(;j<n;j++){
                                            //printf("(%d,%d)\n",i,j);
                                             
                                                        if(a[i*n+j]==0){
                                                                            break;
                                                                                        }
                                                                    else{
                                                                                        max_row_number = i;
                                                                                                    }
                                                                            }
                                }
                 
                    return max_row_number;
}
 
 
 
int main(){
        int i,j;
            int a[10000];
             
                for(i=0;i<4;i++){
                            for(j=0;j<4;j++){
                                            scanf("%d",&a[i*4+j]);
                                                    }
                                }
                 
                    printf("%d\n",maxOnes(a,4));
                        return 0;
}

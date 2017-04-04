#include "array.h"
#include<stdio.h>
#include<stdlib.h>
int binaryroated(int *A,int n,int B) {
   /* if(n==0) return -1;
    int s=0;
    int e=n-1;
    int mid;
    while(s < e) {
        mid = (s+e)/2;
        if(A[mid]==B) return mid;
        if(A[0]<=A[mid]) {
            if(B>=A[0] && B<=A[mid]){
                    e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
        if(B>=A[mid] && B<=A[n-1])
            s=mid+1;
        else
            e =mid-1;

    }}*/
    int N=n;
    int key =B;
     int L = 0;
       int R = N - 1;
        
         while (L <= R) {
                 // Avoid overflow, same as M=(L+R)/2
                     int M = L + ((R - L) / 2);
                          if (A[M] == key) return M;
                 //          
                 //              // the bottom half is sorted
                                   if (A[L] <= A[M]) {
                                         if (A[L] <= key && key < A[M])
                                                 R = M - 1;
                                                       else
                                                               L = M + 1;
                                                                   }
                 //                                                      // the upper half is sorted
                                                                           else {
                                                                                 if (A[M] < key && key <= A[R])
                                                                                        L = M + 1;
                                                                                               else 
                                                                                                       R = M - 1;
                                                                                                           }
                                                                                                             }
    return -1;
}
int main() {
    int a[] = {6,7,8,9,10,11,2,3,4,5};
    int B;
    cin>>B;
    int n = sizeof(a)/sizeof(int);
    printf("%d",binaryroated(a,n,B));
    return 0;
}

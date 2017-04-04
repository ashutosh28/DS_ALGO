#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
 
int main(void) {
        int A[]={ 8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 };
            printf("\n%d",kthsmallest(A,46,9));
                return 0;     
                     }
 
 int kthsmallest(const int* A, int n1, int k) {
         int * K =(int*)malloc(sizeof(int)*k);
             int min=INT_MAX;
                 int i,j;
                  
                      for(i=0;i<n1;i++)
                               {  
                                          if(A[i]<min)
                                                      min = A[i];
                                           
                                               }
                       
                         if (k==1)
                                return min;
                          
                            K[0]=min;
                             
                                for(j=1;j<k;j++)
                                        {   K[j]=INT_MAX;
                                                    for(i=0;i<n1;i++)
                                                             {  
                                                                        if((K[j]>(A[i]-K[j-1])) && (A[i]-K[j-1] > 0))
                                                                             
                                                                                    K[j]=A[i];
                                                                         
                                                                             }
                                                     
                                                        }
                                     for(j=1;j<k;j++)
                                              printf("%d ",K[j]);
                                      
                                      return K[k-1];
                                       
 }

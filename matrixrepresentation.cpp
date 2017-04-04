#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
void printmatrix(int *A,int N){
    int i,j;
    for(i=0;i<2*N-1;i++){
        if(i<N){
            j=0;
            while(j<=i){
                cout<<*((A+j*N)+(i-j));
                j++;
            }
        }else{
            int k =0;
            j=i-(N-1);
            while(j<N){
                cout<<*((A+j*N)+(N-1 - k));
                j++;
                k++;
            }
        }
        cout<<endl;
    }
}
int main(){
    int N;
    cin>>N;
    int A[N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    printmatrix((int*)A,N);
    return 0;
}

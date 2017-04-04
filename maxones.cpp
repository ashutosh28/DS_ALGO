#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    int N,M;
    //scanf("%d %d\n",&N,&M);
    cin>>N>>M;
    int i,j,A[N][M];
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            //scanf("%d ",&A[i][j]);
            cin>>A[i][j];
        }
    }
    int max=0,max1=0;
    for(i=0;i<N;i++) {
        for(j=max1;j<M;j++){
            if(A[i][j]==1){
                if(max1<=j){
                    max = i;
                    max1 = j;
                }
            }
        }
    }
    //printf("\n%d",max);
    cout<<max;
}

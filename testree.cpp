#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
        int N;
            cin>>N;
                int A[N],E[N][N];
                    int i,j,k,val=0,flag=0;
                        for(i=0;i<N;i++){
                                    cin>>A[i];
                        }
                        for(i=0;i<N;i++){
                            for(j=0;j<N;j++){
                                E[i][j]=0;
                            }
                        }
                                                
                            for(k=0;k<N-1;k++){
                                        cin>>i>>j;
                                                E[i][j] = 1;
                                                    }
                                for(i=0;i<N;i++){
                                            flag=0;
                                                    for(j=0;j<N;j++){
                                                                    if(E[i][j]==1){
                                                                                        if(A[i] != A[j]){
                                                                                                                flag=1;
                                                                                                                                    break;
                                                                                                                                                    }
                                                                                                    }
                                                                            }
                                                            if(flag!=1){
                                                                            val++;
                                                                                    }
                                                                }
                                    cout<<val;
                                        return 0;
}

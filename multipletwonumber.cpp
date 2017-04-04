#include <iostream>
#include <cmath>
using namespace std;
int multipletwonumber(int N,int M) {
    if(N==1)
        return M;
    cout<<"A ";
    return M + multipletwonumber(N-1,M);
}
int multipletwo(int N,int M){
    return (N>M)?multipletwonumber(M,N):multipletwonumber(N,M);
}
int main(){
    int N,M;
    cin>>N>>M;
    cout<<multipletwo(N,M);
    return 0;
}

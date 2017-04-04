#include "array.h"
#include<string>
/*string convert(string A,int B) {
    string *str = (string*) malloc(B * sizeof(string));
    char **C = (char*) malloc(B*sizeof(char*));
    int i=0,j=0,z=0;
    int P[B];
    for(i=0;i<B;++i) P[i]=0;
    i=0;
    int len = A.size();
    cout<<A<<" length : "<<len<<endl;
    while(i<len) {
        if(j == B) j=0;
        int index = P[j];
        str[j][index]= A[i];
        cout<<str[j][index]<<" " <<A[i]<<" ";
        P[j] = P[j] + 1;
        cout<<str[j]<<endl;
        j++;i++;
    }
    string F;
    for(i=0;i<B;++i) {
        j=0;
        while(j<P[i])
            F[z++] = str[i][j++];
    }
    return F;



    }*/
char* convert(char *A,int B) {
    char **C = (char**) malloc(B*sizeof(char*));
    int i=0,j=0,z=0;
    for(i=0;i<B;++i) {
        C[i] = (char*) malloc(10*sizeof(char));
    }
    
    int len = 0;
    char *x=A;
    while(*x) len++;
    int P[B];
    for(i=0;i<B;++i) P[i]=0;
    i=0;
    while(i<len) {
        if(j==B) j=0;
        int ind = P[j];
        C[j][ind]=A[i];
        P[j]=P[j]+1;
        j++;
        i++;
    }
    //cout<<C[0]<<endl;*/
    char *F = (char*)malloc(len*sizeof(char));
    for(i=0;i<B;++i) {
        j=0;
        while(C[i][j] && j<P[j]  && z<len) {
            F[z++]= C[i][j];
        }
    }
    return F;
}
int main () {
    char *P = "ABCDEF";
    int B;
    cin>>B;
    char *R=convert(P,B);
        cout<<" "<<P<<endl;
    return 0;
}

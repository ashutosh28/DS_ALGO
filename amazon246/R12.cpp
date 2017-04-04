#include "amazon.h"
int zeroindex(int *A,int len)
{
    cout<<"HYE ASHU"<<endl;
    /*int len=0;
    int *t=A;
    while(*t){
        len++;
        t++;
        cout<<"Ashu"<<*t<<endl;
    }*/
    int i,j,p;
    int max=0,count=0;
    for(i=0;i<len;i++) {
        cout<<A[i]<<" ";
        if(A[i]==0){
            A[i]=1;
            for(j=0;j<len;j++){
                if(A[j] == 1) {
                    count++;
                    if(max<count) {
                        max=count;
                        cout<<j<<" "<<i<<" ";
                        p=i;
                    }
                }else {
                    count=0;
                }
            }
            A[i]=0;
            cout<<" i: "<<i<<" ";
        }
    
    }
    return p;
}
int main() {
    int N,count=0;
    cout<<"Enter no of elements in array: ";
    cin>>N;
    int A[N];
    cout<<"\nEnter elments in array :"<<endl;
    int i,j;
    for(i=0;i<N;i++) {
        cin>>A[i];
        if(A[i]==0)count++;
    }
 //   cout<<count;
    int x = zeroindex(A,N);
    cout<<"\nOutput of ZeroIndex: "<<x<<endl;
    return 0;
}

#include "LRUchache.h"
int main(){
    int N;
    cout<<"Enter No of pages in a program: ";
    cin>>N;
    int L;
    cout<<"\nEnter LRU size: ";
    cin>>L;
    
    LRU lru(L);
    int i,x;
    for(i=0;i<N;i++){
        cin>>x;
        lru.fetchPage(x);
        cout<<endl;
    }
    return 0;
}

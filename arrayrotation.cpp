#include <iostream>
#include <algorithm>

using namespace std;
int binarysearch(int *A,int S,int N,int k)
{
    int mid = (S+N)/2;
    if(A[mid]==k)
        return mid;
    if else (A[mid]
int main(){
    int N;
    cout<<"Enter number of elements in Array: ";
    cin>>N;
    int i=0,k;
    int A[N];
    cout<<"\nEnter elements in array: ";
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<"\nEnter Element to search in array: ";
    cin>>k;
    cout<<"\nIndex of searched element: "<<binarysearch(A,0,N,k);
    cout<<"\nIndex of element from which array is rotated: "<<searchrotated(A);

    return 0;
}

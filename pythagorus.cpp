#include "array.h"
#include <map>
int main()
{
    int n;
    cout<<"Enter Number n: ";
    cin>>n;
    int arr[n+1];
    map<int,int> Hashmap;
    for(int i=0;i<=n;++i)
    {
        Hashmap[i]= i*i;
    }
    int j=n;
    while(j>0)
    {
        for(int i=0;i<=n;++i)
        {
            Hashmap[j]

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int N;
    cin>>N;
    if(N & (N-1))
        cout<<"Not power of two"<<endl;
    else
        cout<<"power of two"<<endl;
    return 0;
}

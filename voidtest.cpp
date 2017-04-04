#include <iostream>
using namespace std;
int main() {
    int a=5;
    int *l=&a;
    void *k = &a;
    //cout<<"value of int "<<*l<<" and void pointer value: "<<*k;
    int *i;
    i=k;
    cout<<*i;
    return 0;
}

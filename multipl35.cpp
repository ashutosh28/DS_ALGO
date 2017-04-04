#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int i;
    int sum =0;
    for(i=1;i<1000;i++) {
        if(i%3 == 0)
            sum = sum + i;
        if(i%5 == 0)
            sum = sum + i;
        if((i%5 == 0) && (i%3 == 0))
            sum = sum - i;
    }
    cout<<"Sum of Multiples of 3 and 5 below 1000 is :"<<sum;
    return 0;
}

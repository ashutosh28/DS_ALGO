#include "array.h"
#include<stdio.h>
#include<stdlib.h>
unsigned int reverse(unsigned int A) {
        unsigned int x=0;
            int i;
                for(i=0;i<32;i++) {
                            x = x|(A&1);
                                    A=A>>1;
                                            x= x<<1;
                                                }
                    return x;
}
int main() {
    unsigned int a=5;
    cout<<reverse(a);
    return 0;
}

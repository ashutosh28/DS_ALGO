#include "array.h"
#include<stdio.h>
#include<stdlib.h>

int value(char a) {
    switch(a) {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
}
int main(){
    char *s= "XXX";
    int sum=0;
    char prev = '%';
    int i;
    int len=0;
    char *x=s;
    while(*x) {
        len++;
        x++;
    }
    for(i=len-1;i>=0;--i){
        if((value(s[i])<sum) && (s[i] != prev))
        {
            sum -= value(s[i]);
            prev = s[i];
        }else{
            sum +=value(s[i]);
            prev = s[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}

#include "time.h"
#include <time.h>

int main(){
    char *str;
    scanf("%s",str);
    clock_t start, end;
    double cpu_time_used;
    int number=0,i,len=0,effectivelen=0;
    char *c1=str;
    while(*c1){
        len++;c1++;
    }
    if(str[1]=='x' | str[1]=='X'){
        effectivelen = len - 2;
    }else effectivelen =len;
    if(effectivelen>16){
        printf("digits are greater than 16.");
        return 0;
    }
    start = clock();
    for(i=len-1;i>=0;i--) {
        if(str[i]=='x' || str[i]=='X') break;
        if(str[i] >='0'&& str[i] <= '9'){
            number = number + (str[i]-'0')*pow(16,len-1-i);
        }else if(str[i] >='a' && str[i]<='f') {
            number = number + (str[i]-'a'+10)*pow(16,len-1-i);
        }else if(str[i] >='A' && str[i]<='F') {
            number = number + (str[i]-'A'+10)*pow(16,len-1-i);
        }
    }
    printf("%d\n",number);
    //printf("%s",str);
    start = clock()-start;
    printf("%f\n",(double)start);
    int number1=5,c=0;
    end = clock();
    for(i=len-effectivelen;i<len;i++) {
        //if(str[i]=='x' || str[i]=='X') break;
        if(str[i] >='0'&& str[i] <= '9'){
           c=c|(str[i]-'0');
        }else if(str[i] >='a' && str[i]<='f') {
           c=c|(str[i]-'a'+10);
        }else if(str[i] >='A' && str[i]<='F') {
           c=c| (str[i]-'A'+10);
        }
        //printf("         AB  \n");
            number1=c;
            c= c<<4;
            

    }
    printf("%d\n",number1);
    end = clock() - end;
    printf("%f\n",(double)end);
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("%f",cpu_time_used);
    return 0;
    }

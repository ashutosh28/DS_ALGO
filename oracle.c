#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){
    int i;
    for(i=0;i<argc;i++){
        printf("%s",argv[i]);
    }
    char *c = "Ashutosh";
    printf("%s%lu",c,strlen(c));
    struct a{
        char ch[10];
        char *str;
    };
    struct a s1;// = {"Ashutosh","Bangalore"};
    //s1.ch[0] = "Ashutosh";
    s1.str = "Bangaliore";
    printf("\n%c%c",s1.ch[0],*s1.str);
    printf("\n%s%s",s1.ch,s1.str);
    return 0;
}

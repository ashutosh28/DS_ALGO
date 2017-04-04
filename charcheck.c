#include <stdio.h>
#include <stdlib.h>
void foo(char *N){
    char *p = malloc(10*sizeof(char));
    p = "Hello world";
    N = p;
}
 int main(){
     char *p = "Hello";
     //printf("%s",*p);
     char *N = NULL;
     foo(&N);
     printf("%s",N);
     return 0;
 }

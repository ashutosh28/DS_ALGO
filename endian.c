#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int a = 0x12345678;
    char *c = (char*)&a;
    int i;
    for(i=0;i<sizeof(int);i++){
       printf("%.2x",c[i]);
    }
    int x = 0x000000ff & (a >> 24);
    int y = 0x0000ff00 & (a >> 8);
    int z = 0x00ff0000 & (a << 8);
    int b = 0xff000000 & (a << 24);
    int res = x | y | z | b;
    c = (char*)&res;
    printf("\n");
    for(i=0;i<sizeof(int);i++){
       printf("%.2x",c[i]);
    }
    
    if(*c)

    printf("%d",*c);
    int *t= NULL;
    *t=1000;
    printf("%d",*t);

    int *p = (int*)malloc(10*sizeof(int));
    p++;
    free(p);
    return 0;
}

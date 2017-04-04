#include "time.h"

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int i=0;
    while(a && a>=b) {
        i++;
        a=a-b;
    }
    printf("\n%d",i);
    return 0;
    main();
    printf("\n%d",i);
}

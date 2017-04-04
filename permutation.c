#include <stdio.h>
#include <string.h>

        static int g,p;
void swap(char *a, char *b) {
        char temp;
            temp = *a;
                *a = *b;
                    *b = temp;
}

void print(char *a, int i, int n,char *b) {
        int j;
        if(i == n) {
            g++;
            printf("%s\n", a);
            if(!strcmp(a,b)){
                p=g;
                printf("HELLO %d rank of %s\n",g,b);
            }
        } else {
            for(j = i; j <= n; j++) {
                swap(a + i, a + j);
                print(a, i + 1, n,b);
                swap(a + i, a + j);
                                                                        
            }
        }
}

int main(void) {
        char a[100],b[100];
            gets(a);
            gets(b);
                print(a, 0, strlen(a) - 1,b);
                printf("%d\n",p);
                    return 0;
}

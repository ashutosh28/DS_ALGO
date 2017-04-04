#include <stdio.h>
/*int main(){
    char str[16] = "The World is";
    str[13] = 'b';
    printf("%s\n",str);
    return 0;
}*/
/*int main() {
    void fun();
    fun();
    printf("\n");
    return 0;
}
void fun() {
    char c;
    if((c = getchar())!= '\n')
        fun();
    printf("%c",c);
}*/




/*int main() {
    char *s [] = {"department","Information","Technology","National"};
    char **ptr[] = {s+3,s+1,s+2,s};
    char ***p;
    p = ptr;
    printf("%s \n",*(*(p)));
    return 0;
}*/



int main() {
    int a[3][3][2] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
    printf("%d %d %d \n",*(*(*(a+0)+2)+1),*(*(*(a+2)+1)+1),*(a[1][1]+1));
    return 0;
}

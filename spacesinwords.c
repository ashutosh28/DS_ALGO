#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
        int T;
            scanf("%d",&T);
                while(T--){
                            int cntspaces=0;
                                    char *s,*ch;
                                            scanf("%s",s);
                                                    int len = 0;
                                                            ch = s;
                                                                    while(*ch){
                                                                                    len++;
                                                                                                if(*ch>='A') cntspaces++;
                                                                                                            ch++;
                                                                                                                    }
                                                                            int i,k=0,flag=0;
                                                                                    char *res = (char*)malloc(sizeof(char)*(len + cntspaces - 1));
                                                                                            while(*s){
                                                                                                            if(*s>='A'){
                                                                                                                                if(flag==0){
                                                                                                                                                    flag=1;
                                                                                                                                                                    res[k++] = (char)((*s - 'A') + 'a');
                                                                                                                                                                                    }else{
                                                                                                                                                                                                            res[k++] = ' ';
                                                                                                                                                                                                                                res[k++] = (char)(*s - 'A') + 'a';
                                                                                                                                                                                                                                                }
                                                                                                                                            }else{
                                                                                                                                                                res[k++] = *s;
                                                                                                                                                                            }
                                                                                                                        s++;
                                                                                                                                }
                                                                                                    printf("%s\n",res);
                                                                                                        }
                    return 0;
}

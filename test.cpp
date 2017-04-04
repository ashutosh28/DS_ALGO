#include "array.h"
void mycopy(char *s1,char *s2)
{
    s2 = (char*)malloc(sizeof(strlen(s1)));
            for(i=0;i<strlen(s1);i++)
            {    s2[i]=s1[i];
            }
}
int main()
{
    char *s1 ="ashutosh";
    char *s2 = "godara";
    mycopy(s1,s2);
    return 0;
}

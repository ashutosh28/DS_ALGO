#include<stdio.h>
int main()
{
    int a[]={3,2,4,0,1};
    int i=0;
    size_t len=sizeof(a)/sizeof(int);
    for(;i<len;i++)
    {
        a[a[i]]=i;
    }
    for(i=0;i<len;++i)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

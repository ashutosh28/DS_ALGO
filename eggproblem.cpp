#include "array.h"
#include <time.h>
#include<limits.h>
int eggdrop(int e,int f);
int max(int x,int y)
{
/*    if(x<y)
        return y;
    else
        return x;
*/
    return (x>y)?x:y;
}
int main()
{
    int e,f;
    char ch;
    clock_t t = clock();
    double T;
    do
    {
        cout<<"Please enter Number of eggs and floors. ";
        cin>>e>>f;
        cout<<"Solution for this egg problem with eggs "<<e<<"and floors "<<f;
        cout<<" : "<<eggdrop(e,f);
        t = clock() - t;
        T = (double)t/CLOCKS_PER_SEC;
        cout<<"\n Time Taken : "<<T;
        cout<<"\nFor again calculation please enter Y else N :";
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');
    return 0;
}
/*int eggdrop(int e,int f)
{
    if(e == 1)
        return f;
    if(f == 0 || f == 1)
        return f;
    int min = INT_MAX;
    int res;
    for(int i=1;i<=f;++i)
    {
        res = 1 + max(eggdrop(e-1,i-1),eggdrop(e,f-i));
        if(res<min)
            min = res;
    }
    return min;
}*/
int eggdrop(int e,int f)
{
    int eggfloor[e+1][f+1];
    int min = INT_MAX;
    int res;
    for(int i=1;i<=e;++i)
    {
        eggfloor[i][1] = 1;
        eggfloor[i][0] = 0;
    }
    for(int i=1;i<=f;++i)
    {
        eggfloor[1][i] = i;
    }

    for(int i=2;i<=e;++i)
    {
        for(int j=2;j<=f;++j)
        {
            eggfloor[i][j] = INT_MAX;
            for(int x=1;x<=j;++x)
            {
                res = 1 + max(eggfloor[i-1][x-1],eggfloor[i][j-x]);
                        if(res < eggfloor[i][j])
                                eggfloor[i][j] = res;
            }
        }
    }
    return eggfloor[e][f];
}

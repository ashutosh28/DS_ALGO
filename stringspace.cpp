#include "array.h"
#include<cmath>
int main()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
    int len = str.length();
    int space=0;
    for(int i=0;i<len;i++)
    {
        if(str[i] == ' ')
        {
            space+=2;
        }
    }
    char newstr[len+space];
    int i=0,j=0;
    cout<<len+space<<endl;
    //for(int i=0;int j=0;i<len;j<len+space;i++;j++)
    while(i<len && j< (len+space))
    {
        if(str[i] == ' ')
        {
            newstr[j++] = '%';
            newstr[j++] = '2';
            newstr[j] = '0';

        }
        else
        {
            newstr[j]=str[i];
        }
        j++;i++;
    }
    cout<<newstr<<endl;
}

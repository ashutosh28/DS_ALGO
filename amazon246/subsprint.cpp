//============================================================================
// Name        : subsprint.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int LCSubstr(string x, string y){
    int m = x.size(), n=y.length();
    int mx = 0;
    int LCSuff[m+1][n+1];

    for(int j=0; j<=n; j++)
        LCSuff[0][j] = 0;
    for(int i=0; i<=m; i++)
        LCSuff[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]) {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
            	if(mx < LCSuff[i][j]) mx = LCSuff[i][j];
            	//cout<<mx <<endl;
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    //cout<<mx <<endl;
    //return mx;
    char *substr = new char[mx+1];
    substr[mx] = '\0';
    int flag = 0;
    int  i, j;
    for(  i = 0; i <= m; i++ ) {
    	for(  j = 0; j <= n; j++ ) {
    		if(LCSuff[i][j] == mx) {
    			flag = 1;
    			break;
    		}
    	}
    	if(flag == 1) break;
    }
    int u = j;
    int w = mx - 1;
    for( j = j-1; j >= u - mx ; j--) {
    	substr[w--] = y[j];
    }
    cout<<substr<<endl;
    /*string longest = "";
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(LCSuff[i][j] > longest.length())
                longest = x.substr((i-LCSuff[i][j]+1) -1, LCSuff[i][j]);
        }
    }
    return longest;*/
    return mx;
}
int main() {
	string a, b;
	cin>>a>>b;
	int x = LCSubstr(a,b);
	cout<<"LCSubstring :" <<LCSubstr(a,b);;
	return 0;
}

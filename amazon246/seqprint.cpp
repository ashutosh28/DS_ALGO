//============================================================================
// Name        : seqprint.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <utility>
#include <climits>
#include <unordered_map>
#include <algorithm>

#define MAX 1000
using namespace std;

int maximum(int a, int b) {
	return a > b ? a : b ;
}
void lcs(char *a, char *b, int m, int n) {
	int DP[m+1][n+1];

	for(int i = 0; i <= m ; i++ ) {
		for(int j = 0; j <= n; j++ ) {
			if(i == 0 || j == 0 ) {
				DP[i][j] = 0;
			}else if (a[i-1] == b[j-1]) {
				DP[i][j] = 1 + DP[i-1][j-1];
			}else {
				DP[i][j] = maximum(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
	cout<<"length of longest Longest commom subsequence is : "<< DP[m][n] <<endl;

	int index = DP[m][n];

	char *seq = new char[index+1];
	seq[index] = '\0';

	int i , j;
	i = m;
	j = n;
	while(i > 0 && j > 0 ) {
		if(a[i-1] == b[j-1]) {
			seq[index - 1] = a[i-1];
			i--;
			j--;
			index--;
		}else if( a[i-1] > b[j-1]) {
			i--;
		}else {
			j--;
		}
	}
	printf("Longest common subsequence is : %s\n", seq);
}
void lcss(string &A, string &B, int m, int n) {
	int DP[m+1][n+1];

	for(int i = 0; i <= m; i++ ) {
		for(int j = 0; j <=n; j++ ) {
			if(i ==0 || j == 0) {
				DP[i][j] = 0;
			}else if (A[i-1] == B[j-1] ) {
				DP[i][j] = 1 + DP[i-1][j-1];
			}else {
				DP[i][j] = maximum(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
	cout<<"longest length of common subsequence is : "<< DP[m][n];

	int index = DP[m][n];
	//char *seq = new char[index+1];
	char seq[index+1];
	seq[index] = '\0';

	int i , j;
	i = m;
	j = n;
	while(i > 0 && j > 0) {
		if(A[i-1] == B[j-1] ) {
			seq[index-1] = A[i-1];
			i--;
			j--;
			index--;
		}else if(A[i-1] > B[j-1]) {
			i--;
		}else {
			j--;
		}
	}
	string s = seq;
	/*for(i = 0; i < index; i++) {
		s += seq[i];
		cout<<endl<<s<<endl;
	}*/
	cout<<"Longest common subsequence is : "<<s<< "size of subsequence" << s.size()<<endl;
}
int main() {
	string A, B;
	cin>>A>>B;
	lcss(A,B,A.size(),B.size());
	char a[MAX], b[MAX];
	scanf("%s %s", a, b);
	lcs(a,b,strlen(a),strlen(b));
	return 0;
}

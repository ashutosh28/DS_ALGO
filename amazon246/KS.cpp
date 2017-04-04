//============================================================================
// Name        : KS.cpp
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
#include <string>
#include <stack>
#include <map>
#include <algorithm>

#define MAX 1000
using namespace std;

int stringsearch(char *s1, char *s2 ) {
	int slen = strlen(s1);
	int plen = strlen(s2);
	int index = -1;

	for(int i = 0; i <= slen - plen ; i++ ) {
		int j;
		for( j = 0; j < plen; j++ ) {
			if(s1[i+j]  != s2[j]) {
				break; // pattern not found
			}
		}
		if(j == plen) { // pattern found
			printf("partten found at index: %d\n", i);
			index = i;
		}
	}
	return index;
}
void computeLPS(char *pat, int *lps, int M){
	int len = 0;
	int i;
	lps[0] = 0;
	i = 1;
	while(i < M) {
		if(pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}else {
			if(len != 0) {
				len = lps[len-1];
			}else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
int KMPsearch(char *s1, char *s2 ) {
	int N = strlen(s1);
	int M = strlen(s2);
	int index = -1;
	int lps[M];
	int j = 0;
	computeLPS(s2,lps,M);
	for(int  i =0; i < N && j < M; i++) {
		if(s2[j] == s1[i]) {
			i++;
			j++;
		}
		if(j == M) {
			printf("Found pattern at index: %d", i-j);
			index = i - j;
			j = lps[j-1];
		}
		else if( i < N && s2[j] != s1[i]) {
			if(j != 0) {
				j = lps[j-1];
			}else {
				i++;
			}
		}
	}
	return index;
}
int main() {
	char s1[MAX], s2[MAX];
	scanf("%s%s", s1, s2);
	int index = stringsearch(s1,s2);
	cout<<"Index of searched pattern: " << index<<endl;
	int idx = KMPsearch(s1,s2);
	cout<<endl<<"Index of searched pattern in KMPsearch is: " << idx <<endl;
	return 0;
}

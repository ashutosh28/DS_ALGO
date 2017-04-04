//============================================================================
// Name        : paranthesis.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

#define MAX 10000
using namespace std;

void generateLegitimateStrings(int pos, int N, int l, int r) {
	if(N < 1)
		return;
	else {
		static char s[MAX];
		if(r == N) {
			printf("%s \n", s);
		}else {
			if(l > r) {
				s[pos] = ')';
				generateLegitimateStrings(pos+1, N, l, r+1);
			}
			if(l < N) {
				s[pos] = '(';
				generateLegitimateStrings(pos+1, N, l+1, r);
			}
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	generateLegitimateStrings(0, N, 0, 0);
	return 0;
}

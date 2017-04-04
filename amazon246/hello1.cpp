//============================================================================
// Name        : hello1.cpp
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
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#define MAX 10000
using namespace std;

int fabPositive(int N) {
	int DP[N+1];
	DP[0] = 0;
	DP[1] = 1;
	for(int i = 2; i <= N; i++) {
		DP[i] = DP[i-1] + DP[i-2];
	}
	return DP[N];
}
// -8, 5, -3, 2, -1, 1, 0
int fabNegative(int N) {
	int DP[N+1];
	DP[0] = 0;
	DP[1] = 1;
	cout<<DP[0]<<" "<<DP[1]<<" ";
	for(int i = 2; i <= N; i++ ) {
		DP[i] = DP[i-2] - DP[i-1];
		cout<<DP[i]<<" ";
	}
	return DP[N];
}
int main() {
	//Armstrong Number
	/*int N, X, cnt = 0, val = 0;
	scanf("%d", &N);
	X = N;
	while(X) {
		cnt++;
		X = X/10;
	}
	X = N;
	cout<<cnt<<endl;
	for(int i = 0; i < cnt && X > 0; i++ ) {
		val = val + pow(X%10,cnt);
		X = X/10;
	}
	if(val == N) {
		printf("Its Armstrong Number\n");
	}else {
		printf("Not Armstrong Number\n");
	}*/


	// fabonacci number
	int N;
	scanf("%d", &N);
	printf("Fabonacci Positive number %d is %d.\n", N, fabPositive(N));
	printf("Fabonacci Positive number %d is %d.\n", N, fabNegative(N));
	return 0;
}

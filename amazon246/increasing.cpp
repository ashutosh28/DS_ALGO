//============================================================================
// Name        : increasing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int LISeq(int *A, int N) {
	if(N == 0) return 0;
	int DP[N], mx = 0, index = -1;
	for(int i = 0; i < N; i++ ) {
		DP[i] = 1;
	}

	for(int i = 1; i < N; i++ ) {
		for(int j = 0; j < i; j++ ) {
			if(A[i] > A[j] && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
				if(mx < DP[i]) {
					mx = DP[i];
					index = i;
				}
			}
		}
	}
	//return mx;
	int seq[mx];
	int res = mx;
	for(int i = index; i >= 0; i-- ) {
		if(DP[i] == res) {
			seq[res - 1] = A[i];
			res--;
		}
	}
	printf("Sequence is: \n");
	for(int i = 0; i < mx; i++ ) {
		printf(" %d ", seq[i]);
	}
	return mx;
}
int monotonicallyincreasing(int *A, int N ) {
	int DP[N], index = -1, mx = 0;
	for(int i = 0 ;i < N; i++ ) {
		DP[i] = 1;
	}

	for(int i = N -1; i > 0; i-- ) {
		for(int j = i; j > 0; j-- ) {
			if(A[j] > A[j - 1]) {
				DP[i] = DP[i] + 1;
			}else
				break;
		}
		if(mx < DP[i]) {
			index = i;
			mx = DP[i];
		}
	}
	//return mx;
	int sub[mx];
	int res = mx;
	printf("\n");
	for(int i = index; i > index - mx ; i-- ) {
		sub[res--] = A[i];
		printf("%d ", A[i]);
	}
	return mx;
}

int main() {
	int N;
	printf("Enter number of elements in Array: ");
	scanf("%d", &N);
	int *A = new int[N];
	for(int  i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
	}
	printf("Length of longest increasing sequence in List is: %d", LISeq(A, N));
	printf("Length of Monotonically Increasing sequence or longest increasing substring: %d", monotonicallyincreasing(A, N));

	return 0;
}

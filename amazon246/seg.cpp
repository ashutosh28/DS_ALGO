//============================================================================
// Name        : seg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : segrate0&1&2.cpp
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
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

using namespace std;
void swap(int *a, int *b ) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void segratingzerosandones(int *A, int N) {
	int i = 0;
	int j = N - 1;
	while(i < j) {
		if(A[i] == 1) {
			swap(&A[i], &A[j]);
			j--;
		}else {
			i++;
		}
	}
}
void segratingZOT(int *a, int N ) {
	int i = 0, j = 0, k = N-1;
	while(i < k) {
		if(a[i] == 2) {
			swap(&a[i], &a[k]);
			k--;
		}else if ( a[i] == 0 ) {
			swap(&a[i], &a[j]);
			j++;
			i++;
		}else {
			i++;
		}
	}
}
int main() {
	int N;
	scanf("  %d", &N);
	printf("Enter numbers in array only 0 and 1 are included :\n");
	int *A = new int[N];
	int *B  =  new int[N];
	for(int  i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
		//B[i] = A[i];
	}
	for(int  i = 0; i < N; i++ ) {
			scanf("%d", &B[i]);
	}
	segratingzerosandones(A, N);

	for(int i = 0; i < N; i++ ) {
		printf("%d ", A[i]);
	}
	segratingZOT(B, N);
	printf("\n");
	for(int i = 0; i < N; i++ ) {
		printf("%d ", B[i]);
	}
	return 0;
}


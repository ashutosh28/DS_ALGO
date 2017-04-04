//============================================================================
// Name        : frac.cpp
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
#include <utility>
#include <climits>
#include <stack>
#include <list>
#include <map>
#include <algorithm>

#define MAX 1000
using namespace std;

template <class T>
struct Fraction {
	T num;
	T den;
};
int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b,a%b);
}
void fraction_reduce(Fraction<int> *F, int N) {
	int i;
	for(i = 0; i < N; i++ ) {
		int GC = gcd(F[i].num,F[i].den);
		F[i].num = F[i].num/GC;
		F[i].den = F[i].den/GC;
	}
}
int lcm(int *A, int N) {
	int res = 1;
	for(int i = 0; i < N; i++ ){
		res = (res * A[i])/gcd(res,A[i]);
	}
	return res;
}
int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
void printallirreduciblefraction(int M) {
	Fraction<int> F[M];
	for(int i = 0; i < M-1; i++ ) {
		F[i].num = M;
		F[i].den = i + 1;
	}
	fraction_reduce(F, M-1);
	for(int i = 0; i < M-1; i++ ) {
		if(F[i].den != 1) {
			printf("\nFraction with irreducible form %d/%d.", F[i].num,F[i].den);
		}
	}

}
int main() {
	int N;
	printf("Enter number of fractions: ");
	scanf("%d", &N);
	Fraction<int> *F = new Fraction<int>[N];
	//Fraction F[N];
	int LCM[N], B[N];
	for(int i = 0; i < N; i++ ) {
		printf("Enter numerator and denominator of Faction number %d : ", i + 1);
		scanf("%d %d", &(F[i].num),&(F[i].den));
		//printf("%d %d", F[i].num ,F[i].den);
	}
	fraction_reduce(F, N);
	for(int  i = 0; i < N; i++ ) {
		printf("Reduce of Fraction %d is %d/%d\n", i, F[i].num, F[i].den);
		LCM[i] = F[i].den;
	}
	int l = lcm(LCM, N);
	printf("\n%d\n", l);
	for(int  i =0; i < N; i++ ) {
		B[i] = F[i].num * (l/F[i].den);
	}
	qsort(B,N,sizeof(int), cmp);
	for(int  i =0; i < N; i++ ) {
			printf("%d ", B[i]);
		F[i].num = B[i];
		F[i].den = l;
	}
	printf("\n");
	fraction_reduce(F,N);
	for(int  i = 0; i < N; i++ ) {
			printf("Reduce of Fraction %d is %d/%d\n", i, F[i].num, F[i].den);

	}
	 int X, Y;
	 cin>>X>>Y;
	 int P, Q;
	 for(int  i = X; i <= Y; i++ ) {
		 printallirreduciblefraction(i);
	 }

	return 0;
}

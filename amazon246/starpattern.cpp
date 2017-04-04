//============================================================================
// Name        : starpattern.cpp
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
#include <cstring>
//#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 10000

using namespace std;
void printPattern(char *B, int N = 5) {
	for(int i = 0; i < N; i++ ) {
		cout<<B[i];
	}
	cout<<endl;
}
void Pattern(int *A, int N, char *B ) {
	int flag = 0;
	int l = 0;
	int k = N - 1;
	while(l <= k) {
		if(flag == 0) {
			B[A[k] - 1] = '*';
			k--;
			printPattern(B, 4);
			flag = 1;
		}else {
			B[A[l] - 1] = '*';
			l++;
			printPattern(B, 4);
			flag = 0;

		}
	}
}
int addNumber(char *C, int N) {
	int a = 0, b = 0, sp = 0, j = -1, k = -1;
	for(int i = N - 1; i >= 0; i-- ) {
		if(sp == 3) {
			break;
		}else {
			if(C[i] == ' ' ) {
					if(sp == 0) {
							j = i+1;
					}else if(sp == 2) {
						k = i + 1;
					}
					sp++;
					cout<<"hello";
			}
		}
		//cout<<" hello";
	}
	cout<<"j: "<<j<<" k: "<<k<<endl;
	for(int i = j; i< N; i++) {
		if(C[i] != ' ' || C[i] != '\0') {
			a = a*10 + C[i] - '0';
		}else{
			break;
		}
		cout<<"a: "<<a<<endl;
	}
	//cout<<"a: "<<a<<endl;
	for(int i = k; i< N; i++) {
		if(C[i] != ' ') {
			b = b*10 + C[i] - '0';
		}else{
			break;
		}
	}
	cout<<"b: "<<b<<endl;
	return a+b;
}
int main() {
	string s;
	getline(cin, s);
	int N;
	scanf("%d", &N);
	int *A = new int[N];
	char *B = new char[N];
	for(int i = 0; i < N; i++ ) {
		scanf("%d", &A[i]);
		B[i] = '_';
	}
	Pattern(A,N,B);
	//string s;
	//char C[MAX];
	//std::getline (std::cin,C);
	//cin.getline(C, MAX);
	char *C = new char[s.size()+1];
	strcpy(C,s.c_str());
	C[s.size()] = '\0';
	cout<<"string length: "<<strlen(C)<< " " << s.size();
	//cout<<"Sum is : "<<addNumber(C,s.size())<<endl;
	cout<<"Sum is : "<<addNumber(C,strlen(C))<<endl;
	return 0;
}

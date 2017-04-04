//============================================================================
// Name        : minstk.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

template <class T>
class StackgetMin {
private:
	stack<T> s;
	stack<T> minstack;
public:
	StackgetMin() {}
	~StackgetMin() {}
	void push(int x) {
		s.push(x);
		if(minstack.empty() || x <= minstack.top() ) {
			minstack.push(x);
		}
	}
	bool pop() {
		if(s.empty()) return false;
		if(s.top() == minstack.top() ) {
			minstack.pop();
		}
		s.pop();
		return true;
	}
	bool getmin(int *mn) ;





};
template <class T>
bool StackgetMin<T>:: getmin(int *mn) {
			if(minstack.empty()) return false;
			else {
				cout<<minstack.top();
				*mn = minstack.top();
			}
			return true;
}
int main() {
	StackgetMin<int> S;
	int Y = 1;
	int N;
	while(Y == 1 ) {
		printf("Enter operation on stack : \n1 for push\n2 for pop\n3 for getmin\n");
		scanf("%d", &N);
		switch(N) {
			case 1:
				int x;
				scanf("%d", &x);
				S.push(x);
				break;
			case 2:
				if(S.pop()) {
					printf("\npoping success\n");
				}else {
					printf("\nStack is empty\n");
				}
				break;
			case 3:
				int y;
				if(S.getmin(&y)) {
					printf("\nMin element in stack is: %d\n", y);
				}else {
					printf("Stack is empty.\n ");
				}
				break;

		}

		printf("Want another operation on stack enter 0/1: ");
		scanf("%d", &Y);
	}
	return 0;
}

//============================================================================
// Name        : Stack_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;
template <typename T>
void printStack(stack<T> s) {
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		cout<<x<<" ";
	}
	cout<<endl;
}
void sortStack(stack<int> &S){
	stack<int> S1;
	while(!S.empty()) {
		int x = S.top();
		S.pop();
		while(!S1.empty() && x < S1.top()) {
			S.push(S1.top());
			S1.pop();
		}
		S1.push(x);
	}
	while(!S1.empty()) {
		S.push(S1.top());
		S1.pop();
	}
}
bool isMatching(stack<char> &S, char c) {
	char x = S.top();
	S.pop();
	if(c == ']' && x == '[') {
		return true;
	}else if ( c == '}' && x == '{') {
		return true;
	}else if ( c == ')' && x == '(') {
		return true;
	}else {
		return false;
	}
	return false;
}
bool isParanthesisBalanced(string s) {
	stack<char> SP;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
			SP.push(s[i]);
		}
		if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
			if(SP.empty()) {
				return false;
			}
			else if(!isMatching(SP,s[i])) {
				return false;
			}
		}
	}
	if(SP.empty()) {
		return true;
	}
	return false;
}
int main() {
	int N, x;
	cout<<"Enter number of elements in stack:";
	cin>>N;
	stack<int> S;
	for(int i = 0; i < N; i++) {
		cin>>x;
		S.push(x);
	}
	printStack(S);
	sortStack(S);
	printStack(S);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout<<"\nNow enter paranthesis string: ";
	string  s;
	cin>>s;
	cout<<"Is paranthesis is balanced : "<<isParanthesisBalanced(s)<<endl;
	return 0;
}

//============================================================================
// Name        : matchB.cpp
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
#include <string>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

bool ArePair(char a, char b) {
	if(a == '(' && b == ')' ) return true;
	else if( a == '{' && b == '}' ) return true;
	else if (a == '[' && b == ']' ) return true;
	return false;
}
bool balanceparenthies(string &s) {
	stack<char> st;
	for(int i = 0; i < s.size(); i++ ) {
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}else if( s[i] == ')' || s[i] == '}' || s[i] == ']') {
			//char a = top(st);
			if( st.empty() || !ArePair( st.top() ,s[i] )) {
				return false;
			}else {
				st.pop();
			}
		}
	}
	return st.empty() ? true : false ;
}
int main() {

	string st;
	cin>>st;
	if(balanceparenthies(st)) {
		cout<<"Banlanced"<<endl;
	}else {
		cout<<"Not Banlanced"<<endl;
	}
	return 0;
}

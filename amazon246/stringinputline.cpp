//============================================================================
// Name        : stringinputline.cpp
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
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 10000

using namespace std;
string countCharInString(string &s) {
	int l = 0, cnt = 1, x = 0;
	int r = s.size();
	string B = "";
	char prev = s[0], current;
	for(int i = 1; i < r; i++ ) {
		current = s[i];
		if(current == prev) {
			cnt++;
		}else{
			B = B + prev;
			//B = B + (char)(cnt + 48);
			x = 0;
			while(cnt) {
				x = x*10 + cnt%10;
				cnt = cnt/10;
			}
			while(x) {
				B = B + (char)(x%10 + 48);
				x = x/10;
			}
			cnt = 1;
		}
		prev = current;
	}
	B = B + prev;
	x = 0;
	while(cnt) {
		x = x*10 + cnt%10;
		cnt = cnt/10;
	}
	while(x) {
		B = B + (char)(x%10 + 48);
		x = x/10;
	}
	//B = B + (char)(cnt + 48);
	return B;
}
void countcharInString1(string &s) {
	int l = 0, cnt = 1, x = 0, r = s.size(), k = 0;
	char current, prev = s[0];
	for(int i = 1; i < r; i++ ) {
		current = s[i];
		if(current == prev) {
			cnt++;
		}else{
			s[k++] = prev;
			x = 0;
			while(cnt) {
				x = x*10 + cnt%10;
				cnt = cnt/10;
			}
			while(x) {
				s[k++] = (char)(x%10 + 48);
				x = x/10;
			}
			cnt = 1;
		}
		prev = current;
	}
	s[k++] = prev;
	x = 0;
	while(cnt) {
		x = x*10 + cnt%10;
		cnt = cnt/10;
	}
	while(x) {
		s[k++] = (char)(x%10 + 48);
		x = x/10;
	}
	char *C = new char[s.size() + 1];
	strcpy(C,s.c_str());
	C[k] = '\0';
	s = C;
}
int main() {
	string s;
	cin>>s;
	//cout<<countCharInString(s)<<endl;
	countcharInString1(s);
	cout<<s<<endl;
	return 0;
}

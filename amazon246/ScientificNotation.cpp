//============================================================================
// Name        : ScientificNotation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s, a, b, d;
	int flag = 0;
	cin>>s;
	a = s[0];
	for(int i = 2; i < s.length(); i++ ){
		if(s[i] != 'e') {
			if(flag == 0) {
				d += s[i];
			}else {
				b += s[i];
			}
		}else {
			flag = 1;
		}
	}
	int len = 0;
	for(int i = 0; i < b.length(); i++ ) {
		len  = len * 10 + b[i] - 48;
	}
	int p = 0, i;
	for(i = 0; i < d.length() ; i++ ) {
		if(p != len) {
			p++;
			a += d[i];
		}else {
			break;
		}
	}
	while(p != len) {
			a += '0';
			p++;
	}
	a += '.';
	for(;i < d.length(); i++) {
		a += d[i];
	}

	int f = a.length();

	if(a[f-1] == '0') {
			if(a[f-2] == '.') {
				a.erase(f-2,2);
			}
	}
	if(a[f-1] == '.') {
		a.erase(f-1,1);
	}
	cout<<a;
	return 0;
}

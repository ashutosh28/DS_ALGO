//============================================================================
// Name        : Pineapplebarks.cpp
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
#include <algorithm>
using namespace std;

int main() {
	int t, s, x;
	scanf("%d%d%d", &t, &s, &x);
	int val = t;
	if(val == x) {
				printf("YES");
				return 0;
	}else {
		while(1) {
				val = val + s;
				if(val == x) {
					printf("YES");
					break;
				}
				if(val + 1 == x) {
					printf("YES");
					break;
				}
				if(val > x) {
					printf("NO");
					break;
				}
			}
		}

	return 0;
}

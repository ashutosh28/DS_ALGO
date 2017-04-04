//============================================================================
// Name        : overlapping_schedule.cpp
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
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

bool isOptionalClassAttend(const vector<vector<int> > &S, int start, int end ) {
	int l = 0;
	int r = S.size();
	// binary search algorithm
	if(end < S[0][0]) { // corner case
		return true;
	}
	if(start > S[r-1][1]) { // corner case
		return true;
	}
	while(l < r) {
		int mid = l + (r - l)/2 - 1;
		if(S[mid][1] <= start ) {
			if( S[mid+1][0] >= end ) {
				return true;
			}else {
				l = mid + 1;

			}
		}else {
			r = mid - 1;
		}
	}
	return false;
}
int main() {
	int N, OP, flg = 0;
	printf("Enter Number of classes in current schedule: ");
	scanf("%d", &N);
	vector<vector<int> > S(N, vector<int>(2));
	printf("\nEnter starting and ending time of classes in current schedule:");
	for(int i = 0; i < N; i++ ) {
		printf("\nClass %d : ", i);
		scanf("%d%d", &S[i][0], &S[i][1]);
	}
	printf("\nEnter number of optional classes: ");
	scanf("%d", &OP);
	vector<vector<int> > O(N, vector<int>(2));
	printf("\nEnter starting and ending time of classes in optional schedule:");
	for(int i = 0; i < OP; i++ ) {
		printf("\nOptional Class %d : ", i);
		scanf("%d%d", &O[i][0], &O[i][1]);
	}
	// optional classes can Akshay attend without them clashing (conflicting) with his existing schedule
	printf("\nOptional Classes to be attend: ");
	for(int i = 0; i < OP; i++ ) {
		int y = O[i][0];
		int z = O[i][1];
		if( isOptionalClassAttend(S, y, z) ) {
			printf("\nClass with start %d and end time %d:", O[i][0], O[i][1]);
			flg = 1;
		}
	}
	if(flg == 0) {
		printf("No optional class");
	}
	return 0;
}

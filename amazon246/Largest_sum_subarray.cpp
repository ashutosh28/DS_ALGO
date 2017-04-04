//============================================================================
// Name        : Largest_sum_subarray.cpp
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
#include <map>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int i, N, x, y, flg =0;
	printf("Enter number of elements in array:");
	scanf("%d", &N);
	printf("Enter numbers in array:");
	int A[N];
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int max_final = 0, max_till_here = 0;
	for(i = 0; i < N; i++) {
		max_till_here += A[i];
		if(max_till_here < 0) {
			flg = 0;
			max_till_here = 0;
		}
		//max_final = max(max_final,max_till_here);
		if(max_final < max_till_here) {
			if(flg == 0) {
				x = i;
				flg = 1;
			}
			y = i;
			max_final = max_till_here;
		}
	}
	cout<<"Largest_sum is: "<<max_final<<endl;
	cout<<"Index from "<<x<< " to "<<y<<endl;
	return 0;
}

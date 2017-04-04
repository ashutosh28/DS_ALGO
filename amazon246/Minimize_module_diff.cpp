//============================================================================
// Name        : Minimize_module_diff.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;
void inputElements(vector<int> &V) {
	static int a = 1;
	int  i;
	printf("Please enter %lu elements in array%d: ", V.size(),a++);
	for(i = 0; i < V.size(); i++) {
		scanf("%d", &V[i]);
	}
}
void printArray(vector<int> &V) {
	for(int i = 0; i < V.size(); i++) {
		printf("%d ", V[i]);
	}
	cout<<endl;
}

void minimizeModule(vector<int> &A, vector<int> &B, vector<int> &C) {
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	printArray(A);
	printArray(B);
	printArray(C);
	int i = 0, j = 0, k = 0;
	int diff = INT_MAX;
	int x, y, z;
	//Logic is minimize the max-min diffrence
	while(i < A.size() && j < B.size() && k < C.size()) {
		int mini, maxi;

		mini = (B[j] < C[k] ? B[j] : C[k]);
		mini = A[i] < mini ? A[i] : mini;
		maxi = (B[j] > C[k] ? B[j] : C[k]);
		maxi = A[i] > maxi ? A[i] : maxi;

		if(maxi - mini < diff) {
			x = i;
			y = j;
			z = k;
			diff = maxi - mini;
		}

		if(diff == 0) break;

		//Incrementing index of array which has minimum element out of 3 elements for minimize max-min diff
		if(mini == A[i]) i++;
		else if( mini == B[j]) j++;
		else k++;
	}
	cout<<"Resulting tuple is :"<<A[x]<<" "<<B[y]<<" "<<C[z];
}
int main() {
	int l1, l2, l3;
	printf("Please enter size of arrays 1, 2 & 3 resp:");
	scanf("%d%d%d", &l1, &l2, &l3);
	vector<int> A(l1), B(l2), C(l3);
	inputElements(A);
	inputElements(B);
	inputElements(C);

	minimizeModule(A,B,C);

	return 0;

}

//============================================================================
// Name        : Employee.cpp
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

int main() {
	int N, M;
	printf("Enter Number of Employees in company: ");
	scanf("%d", &N);
	vector<vector<int> > EMP(N, vector<int>(2));
	printf("\nEnter employee no. of the supervisor of employee and  likability score: ");
	for(int i = 0; i < N; i++ ) {
		printf("\nEmployee %d :", i+1);
		scanf("%d%d", &EMP[i][0], &EMP[i][1]);
	}
	printf("\nEnter M: ");
	scanf("%d", &M);
	int res[M], hash[N];
	for(int  i = 0; i < N; i++ ) {
		hash[i] = 0;
	}
	struct CMP
	{
	    bool operator()(const std::vector<int>& l,
	                    const std::vector<int>& r) const
	    {
	        return l[1] < r[1];
	    }
	};
	sort(EMP.begin(), EMP.end(), CMP());// sort according to likability.

	int j = M-1, max_sum = 0;
	for(int i = N - 1; i >= 0 && j >=0; i--) {
		if(hash[i] == 0) {
			res[j--] = i+1;
			max_sum += EMP[i][1];// max_sum value for likability.
			hash[EMP[i][0]] = 1;// removing supervisor

		}
	}
	//List of M employee for party
	for(int  i = 0; i < M; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}

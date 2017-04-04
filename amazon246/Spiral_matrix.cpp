//============================================================================
// Name        : Spiral_matrix.cpp
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
#include <utility>
#include <algorithm>

using namespace std;
int ROW,COL;
void printSpiralMatrix(vector<vector<int> > &M) {
	int n = M.size();
	//int m = M[0].size();
	int m = COL;
	int l = 0, k = 0, i;
	while(l < n && k < m) {
		for(i = k; i < m; i++) {
			cout<<" "<<M[l][i];
		}
		l++;
		for(i = l; i < n; i++) {
			cout<<" "<<M[i][m-1];
		}
		m--;
		for(i = m - 1; i >= k; i--){
			cout<<" "<<M[n-1][i];
		}
		n--;
		for(i = n - 1; i >= l; i--) {
			cout<<" "<<M[i][k];
		}
		k++;
	}
}
void printMatrix(vector<vector<int> > M) {
	for(int i = 0; i < ROW; i++) {
		for(int j  = 0; j < COL; j++) {
			cout<<" "<<M[i][j];
		}
		cout<<endl;
	}
}
int main() {
	cout<<"Enter Numbers of Rows and Cols: ";
	cin>>ROW>>COL;
	vector<vector<int> > M(ROW,vector<int>(COL));
	cout<<"Now Enter elements of matrix:";
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			cin>>M[i][j];
		}
	}
	printMatrix(M);
	printSpiralMatrix(M);
	return 0;
}

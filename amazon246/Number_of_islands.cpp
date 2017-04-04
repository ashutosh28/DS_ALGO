//============================================================================
// Name        : Number_of_islands.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int ROW;
int COL;
template <typename T>
void print_Matrix(vector<vector<T> > &M) {
	cout<<M.size()<<" "<< M[0].size()<<endl;
	int r = M.size();
	int c = M[0].size();
	for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				//printf("%d", M[i][j]);
				cout<<M[i][j];
			}
			printf("\n");
		}
}
bool isSafe(vector<vector<int> > &M,int r, int c, vector<vector<bool> > &visited) {
	return ((r >= 0) && (r < ROW) && (c >= 0) && (c < COL) && M[r][c] && !visited[r][c]);
}
void DFS1(vector<vector<int> > &M, int r, int c, vector<vector<bool> > &visited) {
	static int rowhr[] = {-1,-1,-1,0,0,1,1,1};
	static int colhr[] = {-1,0,1,-1,1,-1,0,1};

	visited[r][c] = true;
	for(int k = 0; k < 8; k++) {
		if(isSafe(M,r+rowhr[k],c+colhr[k],visited)) {
			DFS1(M,r+rowhr[k],c+colhr[k],visited);
		}
	}
}
int number_of_island(vector<vector<int> > &M){
	vector<vector<bool> > visited(M.size(), vector<bool>(COL,false));
	print_Matrix(visited);

	int count = 0;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(M[i][j] && !visited[i][j]) {
				DFS1(M,i,j,visited);
				count++;
			}
		}
	}
	return count;
}
int max(int a, int b) {
	return (a > b ? a : b );
}
void DFS2(vector<vector<int> > &M, int r, int c, vector<vector<bool> > &visited, int &count) {
	static int rowhr[] = {-1,-1,-1,0,0,1,1,1};
	static int colhr[] = {-1,0,1,-1,1,-1,0,1};

	visited[r][c] = true;
	for(int k = 0; k < 8; k++) {
		if(isSafe(M,r+rowhr[k],c+colhr[k],visited)) {
			count++;
			DFS2(M,r+rowhr[k],c+colhr[k],visited,count);
		}
	}
}
int largest_Region(vector<vector<int> > &M) {
	vector<vector<bool> > visited(M.size(), vector<bool>(COL,false));
	print_Matrix(visited);

	int result = INT_MIN;
	for(int i =0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(M[i][j] && !visited[i][j]) {
				int count = 1;
				DFS2(M,i,j,visited,count);

				result = max(result,count);
			}
		}
	}
	return result;
}
int main() {
	int i, j;
	scanf("%d%d", &ROW, &COL);
	vector<vector<int> > M(ROW,vector<int>(COL,0));
	print_Matrix(M);

	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COL; j++) {
			scanf("%d", &M[i][j]);
		}
	}
	print_Matrix(M);
	cout<<"\n"<<"Number of Islands"<<number_of_island(M)<<endl;
	cout<<"LargestRegionOfIslands"<<largest_Region(M)<<endl;

	return 0;
}

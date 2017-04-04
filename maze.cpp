#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, vector<vector<int> > v){
	return ( x>=0 && x<v.size() && y>=0 && y<v[0].size());
}
void solUtil(const vector<vector<int> > &v, vector<vector<int> > &sol,int x, int y, int k ) {
	sol[x][y] = v[x][y];
	int i, j;
	for(i = 0; i < v.size(); i++) {
		for(j = 0; j < v[0].size(); j++) {
			if(isSafe(i-1,j,v)) {
				if(sol[i-1][j] + v[i][j] < sol[i][j]) {
					sol[i][j] = sol[i-1][j] + v[i][j];
				}
			}
			if(isSafe(i-1,j-1,v)) {
				if(sol[i-1][j-1] + v[i][j] < sol[i][j]) {
					sol[i][j] = sol[i-1][j-1] + v[i][j];
				}
			}
			if(isSafe(i,j-1,v)){
				if(sol[i][j-1] + v[i][j] < sol[i][j]) {
					sol[i][j] = sol[i][j-1] + v[i][j];
				}
			}
		}
	}
}
int solution(const vector<vector<int> > &v, int K) {
	int r = v.size();
	int c = v[0].size();
	vector<vector<int> > sol(r,vector<int>(c));
	int i, j;
	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++){
			//sol.push_back(50);
			sol[i][j] = INT_MAX;
		}
	}
	solUtil(v,sol,0,0,K);
	if(sol[r-1][c-1] == INT_MAX || sol[r-1][c-1] > K) {
		return -1;
	}
	return sol[r-1][c-1];
}
int main()
{
    int T, N, M, K, i, j, x;
    scanf("%d", &T);

    while(T--) {
    	scanf("%d%d%d", &N, &M, &K);
			vector<vector<int> > v(N,vector<int>(M));
    	for(i = 0; i < N; i++) {
    		for(j = 0; j <M; j++) {
    			scanf("%d", &x);
    			//v.push_back(x);
					v[i][j] = x;
    		}
    	}
    	printf("%d\n",solution(v,K));
    }
    return 0;
}

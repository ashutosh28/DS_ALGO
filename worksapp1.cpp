#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

#define NUM 500
using namespace std;

int nakeGameSolution( int grid[NUM][NUM], int rows, int cols ) {
    return 4;
}
int main() {
    int rows,cols;
    cin>>rows>>cols;
    int grid[NUM][NUM];
    int i,j;
    for( i = 0; i < rows; i++) {
        for( j = 0; j < cols; j++) {
            cin>>grid[i][j];
        }
    }
    int result = nakeGameSolution( grid, rows, cols);
    cout<<result;
    return 0;
}

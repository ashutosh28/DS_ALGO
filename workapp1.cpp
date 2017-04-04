#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
long long int max( long long int a, long long int b) {
    return a > b ? a : b;
}
long long int snakeGameSolution( const vector< vector<int> > &grid ) {
    int row = grid.size();
    int col = grid[0].size();
    int i, j,last;
    long long int tmp, maxScore = 0;
    vector< vector<int> > maxScoreGrid( row, vector<int>(col+1) );

    for( i =0; i < row; i++) {
        for( j = 0; j <= col; j++) {
            maxScoreGrid[i][j] = 0;
            //cout<<maxScoreGrid[i][j]<<" ";
        }
    }

    for( j = 0; j < col; j++ ) {
        for( i = 0; i < row; i++ ) {
            if( grid[i][j] == -1 ) {
                maxScoreGrid[i][j+1] = -1;
                continue;
            }

            if( maxScoreGrid[i][j] == -1 ) 
                continue;
            
            // move down
            last=i;
            tmp=maxScoreGrid[i][j]+grid[i][j];
            maxScoreGrid[i][j+1]=max(tmp,maxScoreGrid[i][j+1]);
            
            for(int k=i+1;;k++){
                k=(k+row)%row;
                if(grid[k][j]==-1 || k==i)
                    break;
                else{
                    // transported
                    if(abs(k-last)>1){
                        maxScoreGrid[k][j+1]=maxScoreGrid[k][j+1]>grid[k][j]?maxScoreGrid[k][j+1]:grid[k][j];
                        tmp=grid[k][j];
                    }
                    else{
                        tmp+=grid[k][j];
                        if(tmp>maxScoreGrid[k][j+1])
                            maxScoreGrid[k][j+1]=tmp;
                    }
                    last=k;
                }
            }
            
            //move up
            last=i;
            tmp=maxScoreGrid[i][j]+grid[i][j];
            maxScoreGrid[i][j+1]=max(tmp,maxScoreGrid[i][j+1]);
            
            for(int k=i-1;;k--){
                k=(k+row)%row;
                if(grid[k][j]==-1 || k==i)
                    break;
                else{
                    if(abs(k-last)>1){
                        maxScoreGrid[k][j+1]=maxScoreGrid[k][j+1]>grid[k][j]?maxScoreGrid[k][j+1]:grid[k][j];
                        tmp=grid[k][j];
                    }
                    else{
                        tmp+=grid[k][j];
                        if(tmp>maxScoreGrid[k][j+1])
                            maxScoreGrid[k][j+1]=tmp;
                    }
                }
                last=k;
            }
        }
    }
    
    for(int i=0;i<row;i++)
        maxScore=max(maxScore,maxScoreGrid[i][col]);
    
    
    return maxScore;
            
}   
int main() {
    int n, m, i, j, data;
    scanf("%d%d", &n, &m);
    
    vector<vector<int> > grid( n, vector<int>(m) );
    for( i = 0; i < n; i++ ) {
        for( j = 0; j < m; j++ ) {
            scanf("%d", &data);
            grid[i][j] = data;
        }
    }
    
    long long int maxScore = snakeGameSolution(grid);
    if(maxScore == 0) {
        maxScore = -1;
    }
    printf("%lld", maxScore);
    return 0;
}
    
            

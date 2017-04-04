#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <climits>
#include <algorithm>

using namespace std;

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}
void func(const vector<vector<int> > &grid, vector<vector<int> > &maxScoreDPTable, int x, int y) {

            
            tmp = maxScoreDPTable[i][j] + grid[i][j];
            maxScoreDPTable[i][j+1] = max(tmp, maxScoreDPTable[i][j+1]); 
            
            // moving down after right move
            k = i;
            while(1) {
                k++;
                k = (k + row) % row;
                if(grid[k][j] == -1 || k == i)
                    break;
                else {
                    if(k == 0) { // moving from last row to first row 
                        if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                            maxScoreDPTable[k][j+1] = grid[k][j];
                        }
                        tmp = grid[k][j];
                    } else {
                        tmp = tmp + grid[k][j];// adding values while successful down move
                        if(tmp > maxScoreDPTable[k][j+1]) {
                            maxScoreDPTable[k][j+1] = tmp;
                        }
                    }
                }
            }
 
            tmp = maxScoreDPTable[i][j] + grid[i][j];
            maxScoreDPTable[i][j+1] = max(tmp, maxScoreDPTable[i][j+1]); 
            
            // moving up after right move
            k = i;
            while(1) {
                k--;
                k = (k + row) % row;
                if(grid[k][j] == -1 || k == i)
                    break;
                else {
                    if(k == row - 1) { // moving from first row to last row
                        if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                            maxScoreDPTable[k][j+1] = grid[k][j];
                        }
                        tmp = grid[k][j];
                    } else {
                        tmp = tmp + grid[k][j];// adding values while successful up move
                        if(tmp > maxScoreDPTable[k][j+1]) {
                            maxScoreDPTable[k][j+1] = tmp;
                        }
                    }
                }
            }
}
long long int snakeGameSolution(const vector<vector<int> > &grid, int x, int y) {
    int row, col, i, j, k;
    row  = grid.size();
    col = grid[0].size();
    long long int tmp, maxScore = 0;
    vector<vector<int> > maxScoreDPTable(row,vector<int>(col+1)); // Creating 2D vector for grid points with No. of column is col+1 for Dynamic Programming solution with default values of 0 to all points.

    for(j = 0; j < col; j++) {
        for(i = 0; i < row; i++) {
            if(grid[i][j] == -1) {
                maxScoreDPTable[i][j+1] = -1;
                continue;
            }
            
            if(maxScoreDPTable[i][j] == -1) // cannot move right 
                continue;
            
            tmp = maxScoreDPTable[i][j] + grid[i][j];
            maxScoreDPTable[i][j+1] = max(tmp, maxScoreDPTable[i][j+1]); 
            
            // moving down after right move
            k = i;
            while(1) {
                k++;
                k = (k + row) % row;
                if(grid[k][j] == -1 || k == i)
                    break;
                else {
                    if(k == 0) { // moving from last row to first row 
                        if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                            maxScoreDPTable[k][j+1] = grid[k][j];
                        }
                        tmp = grid[k][j];
                    } else {
                        tmp = tmp + grid[k][j];// adding values while successful down move
                        if(tmp > maxScoreDPTable[k][j+1]) {
                            maxScoreDPTable[k][j+1] = tmp;
                        }
                    }
                }
            }
 
            tmp = maxScoreDPTable[i][j] + grid[i][j];
            maxScoreDPTable[i][j+1] = max(tmp, maxScoreDPTable[i][j+1]); 
            
            // moving up after right move
            k = i;
            while(1) {
                k--;
                k = (k + row) % row;
                if(grid[k][j] == -1 || k == i)
                    break;
                else {
                    if(k == row - 1) { // moving from first row to last row
                        if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                            maxScoreDPTable[k][j+1] = grid[k][j];
                        }
                        tmp = grid[k][j];
                    } else {
                        tmp = tmp + grid[k][j];// adding values while successful up move
                        if(tmp > maxScoreDPTable[k][j+1]) {
                            maxScoreDPTable[k][j+1] = tmp;
                        }
                    }
                }
            }
        }
        if(j == y) { // found row of point
            int d;
            for(d = 0; d < row; d++ ){
                cout<<maxScoreDPTable[d][j+1]<<" ";
            }
            cout<<endl;
            if(maxScoreDPTable[x][j+1] - grid[x][j] == maxScoreDPTable[x][j] ) { //comes from right
                int a, b;
                for(a = 0; a < row; a++ ) {
                    //if(a != x) {
                        maxScoreDPTable[a][j+1] = 0;
                    //}
                }

                tmp = maxScoreDPTable[x][j] + grid[x][y];
                maxScoreDPTable[x][j+1] = max(maxScoreDPTable[x][j+1],tmp);
                k = x;
                while(1) {
                    k++;
                    k = (k + row) % row;
                    if(grid[k][j] == -1 || k == i)
                        break;
                    else {
                        if(k == 0) { // moving from last row to first row 
                            if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                                maxScoreDPTable[k][j+1] = grid[k][j];
                            }
                            tmp = grid[k][j];
                        } else {
                            tmp = tmp + grid[k][j];// adding values while successful down move
                            if(tmp > maxScoreDPTable[k][j+1]) {
                                maxScoreDPTable[k][j+1] = tmp;
                            }
                        }
                    }
                }
                
                tmp = maxScoreDPTable[x][j] + grid[x][y];
                maxScoreDPTable[x][j+1] = max(tmp, maxScoreDPTable[x][j+1]); 
            
                // moving up after right move
                k = x;
                while(1) {
                    k--;
                    k = (k + row) % row;
                    if(grid[k][j] == -1 || k == i)
                        break;
                    else {
                        if(k == row - 1) { // moving from first row to last row
                            if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                                maxScoreDPTable[k][j+1] = grid[k][j];
                            }
                            tmp = grid[k][j];
                        } else {
                            tmp = tmp + grid[k][j];// adding values while successful up move
                            if(tmp > maxScoreDPTable[k][j+1]) {
                                maxScoreDPTable[k][j+1] = tmp;
                            }
                        }
                    }
                }
            }
            if(x > 0 && x < row - 1) {
                if (maxScoreDPTable[x][j+1] - grid[x][j] == maxScoreDPTable[x-1][j+1] ) { // comes from upside
                        int r w, flag = 0;
                        r = x;
                        while(1) {
                            r--;
                            r = (r + row) & row;
                            if(grid[r][j] == -1 || r == x) {
                                w = r;
                                break;
                            }else {
                                if( r == 0 ) {
                                    if(maxScoreDPTable[r][j+1] != grid[r][j]) {
                                        w = r;
                                        break;
                                    }else {
                                        flag = 1;
                                        continue;
                                    }
                                }else {
                                    if(maxScoreDPTable[r][j+1] - grid[r][j] != maxScoreDPTable[r-1][j+1]) {
                                        w = r;
                                        break;
                                    }else {
                                        continue;
                                    }
                                }
                            }    
                        }
                        if(flag) {
                            int e;
                            for( e = x + 1; e <= w; e++) {
                                maxScoreDPTable[e][j+1] = 0;
                            }
                            tmp = maxScoreDPTable[x][j+1]; 
                            //maxScoreDPTable[x][j+1] = max(maxScoreDPTable[x][j+1],tmp);
                            k = x;
                            while(1) {// move down
                            k++;
                            k = (k + row) % row;
                            if(grid[k][j] == -1 || k == i)
                            break;
                            else {
                                if(k == 0) { // moving from last row to first row 
                                    if(maxScoreDPTable[k][j+1] < grid[k][j]) {
                                    maxScoreDPTable[k][j+1] = grid[k][j];
                                }
                                tmp = grid[k][j];
                            } else {
                                tmp = tmp + grid[k][j];// adding values while successful down move
                                if(tmp > maxScoreDPTable[k][j+1]) {
                                    maxScoreDPTable[k][j+1] = tmp;
                                }
                            }
                            }
                            }
                    }else {
                        int e;
                        for(e = 0; e< row; e++) {
                            if(e = w; e< x; e++) {
                                maxScoreDPTable[e][j+1] = 0;
                    }
            }
            for(d = 0; d < row; d++ ){
                cout<<maxScoreDPTable[d][j+1]<<" ";
            }
            cout<<endl;
        }
    }

    for(i = 0; i < row; i++) { // Calculating highest value in right most column.
        maxScore = max(maxScore, maxScoreDPTable[i][col]);
    }

    return maxScore;
}
int main() {
    int row, col, i, j, x, y;
    scanf("%d%d", &row, &col); 
    vector<vector<int> > grid(row,vector<int>(col));

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    scanf("%d%d", &x, &y);
    long long int maxScore = snakeGameSolution(grid, x, y);
    if(maxScore == 0) { // when snake cannot reach the right side
        maxScore = -1;
    }
    printf("%lld", maxScore);

    return 0;
}

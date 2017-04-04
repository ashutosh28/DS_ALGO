#include <iostream>

using namespace std;
int rows,cols;
int sol(int grid[][cols]){
    return grid[rows-1][cols-1];
}
int main() {
    cin>>rows>>cols;
    int grid[rows][cols];
    int i,j;
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            cin>>grid[i][j];
        }
    }
    cout<<sol(grid);
    return 0;
}

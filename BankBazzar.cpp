#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct point {
    int x,y;
};
struct queueNode {
    point pt;
    int dist;
};
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isValid(int row, int col, int ROW, int COL )
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
int calculateTime(const vector<vector<char> > &V, point &src) {
    int N = V.size();
    int M = V[0].size();
    int visited[N][M];
    memset(visited, 0, sizeof (visited));
    int i, j, result = INT_MIN;
    if(V[0][0] == 'B') {
        visited[0][0] = 0;
    }
     queue<queueNode> q;
     queueNode s = {src, 0};
     q.push(s);
     
     while(!q.empty()) {
         queueNode curr = q.front();
         point pt = curr.pt;
         cout<<"A "<<pt.x<<" B "<<pt.y<<" V's "<<V[pt.x][pt.y]<<endl;
         if(V[pt.x][pt.y] == 'C') {
            cout<<"hello"<<endl;
             if(result <= curr.dist) {
                 result = curr.dist;
             }
         }
         q.pop();
         
         for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            if (isValid(row, col, N, M) && (V[row][col] == '.' || V[row][col] == 'C'))
            {
                
                //visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
     }
     return result;
     
    
    
}
int main() {
    int T, N, M;
    scanf("%d", &T);
    while(T) {
        scanf("%d%d", &N, &M);
        vector< vector<char> > v(N,vector<char>(M));
        for(int i = 0 ; i < N; i++){
            string s;
            cin>>s;
            for(int j = 0; j < M; j++) {
                v[i][j] = s[j];
            }
        }
        point src = {0,0};
        int x = calculateTime(v,src);
        cout<<x<<endl;
        if(x == INT_MIN) {
            x = -1;
        }
        cout<<x<<endl;
        T--;
    }
	// your code goes here
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    vector<int> eds;
};
Node node[100001];
int dis[100001];    //dis[i]表示结点i离最近标记结点的距离
int m, n;

//更新以x为根节点，p为x的父节点的子树的状态，有剪枝
void dfs(int x, int p) {
    vector<int> vecs = node[x].eds;
    for (int i = 0; i < vecs.size(); ++i) {
        if (vecs[i] == p)
            continue;
        if (dis[vecs[i]] == -1 || dis[vecs[i]] > dis[x] + 1) {
            dis[vecs[i]] = dis[x] + 1;
            dfs(vecs[i], x);
        }
    }
}

int main() {
    clock_t t;
    t = clock();
    memset(dis, -1, sizeof(dis));
    
    scanf("%d%d", &m, &n);
    int a, b;
    for (int i = 1; i < m; ++i) {
        scanf("%d%d", &a, &b);
        node[a].eds.push_back(b);
        node[b].eds.push_back(a);
    }
    dis[1] = 0;
    dfs(1, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        if (a == 1) {
            dis[b] = 0;
            dfs(b, 0);
        }
        else {
            printf("%d\n", dis[b]);
        }
    }
    t = clock() - t;
    double time_tak = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_tak;
    return 0;
}

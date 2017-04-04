#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    bool flag;    //记录该节点是否被标记
    vector<int> eds;
    
    Node() {
        flag = false;
    }
};
Node node[100001];
int m, n;

struct State {
    int par;    //父节点
    int no;
    int dis;
};

int bfs(int x) {
    queue<State> que;
    State sta;
    sta.par = 0;
    sta.no = x;
    sta.dis = 0;
    que.push(sta);
    while (!que.empty()) {
        State cur = que.front();
        que.pop();
        if (node[cur.no].flag)
            return cur.dis;
        vector<int> vecs = node[cur.no].eds;
        for (int i = 0; i < vecs.size(); ++i) {
            if (vecs[i] == cur.par)
                continue;
            State ns;
            ns.par = cur.no;
            ns.no = vecs[i];
            ns.dis = cur.dis + 1;
            que.push(ns);
        }
    }
}

int main() {
    clock_t t;
    t = clock();
    scanf("%d%d", &m, &n);
    int a, b;
    for (int i = 1; i < m; ++i) {
        scanf("%d%d", &a, &b);
        node[a].eds.push_back(b);
        node[b].eds.push_back(a);
    }
    
    node[1].flag = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        if (a == 1) {
            node[b].flag = true;
        }
        else {
            int dis = bfs(b);
            printf("%d\n", dis);
        }
    }
    t = clock() - t;
    double time_tak = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_tak;
    return 0;
}

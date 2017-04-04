#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <climits>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <ctime>

#define VMAX 100001  // max vertices in graph starting from 1 not from 0

using namespace std;

class Graph {
        int V; //No of vertices in graph
        list<int> *adj; //Pointer to array contain Adjacency list of vertices
    public:
        Graph( int V ); // Graph constructor
        void addEdge( int x, int y ); // Add egde to graph
        void printgraph(int n){
            int i;
            for(i=0;i<=n;i++) {
                list<int>::iterator it;
                for(it = adj[i].begin(); it != adj[i].end(); it++ ) {
                    cout<<*it<< " ";
                }
                
            }
        }
        void calculatedis( int vertex, int parent );
        int *dis; // Pointer to array containing dis of vertices from festive city
};


Graph::Graph( int V ) {
    this->V = V;
    adj = new list<int>[V];
    dis = new int[V];
    for(int i=0;i<V;i++) dis[i] = -1;
    //memset( &dis, -1, sizeof(dis) );
}

/*struct Graph {
    list<int> adj;
};
Graph G[VMAX];*/
void Graph::addEdge( int x, int y ) {
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void Graph::calculatedis(  int vertex, int parent ) {
    //list<int> ves = G[vertex].adj;
    list<int>::iterator it;
    //int i;
    for(it = adj[vertex].begin(); it != adj[vertex].end(); it++ ) {
        if ( *it == parent ) {
            continue;
        }
        if ( dis[*it] == -1 || dis[*it] > dis[vertex] + 1 ) {
            dis[*it] = dis[vertex] + 1;
            //cout<<dis[ves[i]]<<" ";
            calculatedis(*it, vertex);
        }
    }
}

int main() {
    clock_t t;
    t = clock();
    int n, m; // n is No. of vertices, m is No. of queries 
    scanf("%d%d", &n, &m);
    
    Graph G(n+1);
    //Graph G(VMAX); // Initialising Graph
    //memset( G.dis, -1, sizeof(*(G.dis)) );
    int x, y, i;
    for( i = 1; i < n; i++ ) {
        scanf("%d%d", &x, &y);
        G.addEdge(x, y);
        //G.printgraph(n);
    }
    G.dis[1] = 0; // Initialy 1 is festive city
    G.calculatedis(1, 0);
    for( i = 0; i < m; i++ ) {
        scanf("%d%d", &x, &y);
        if( x == 1) {
            G.dis[y] = 0;
            G.calculatedis(y, 0);
        } else {
            printf("%d\n", G.dis[y]);
        }
    }
    t = clock() - t;
    double time_tak = ((double)t)/CLOCKS_PER_SEC;
    cout<<time_tak;
    return 0;
    
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <climits>
#include <algorithm>

#define VMAX 100001  // max vertices in graph starting from 1 not from 0

using namespace std;

class Graph {
        int V; //No of vertices in graph
        list<int> *adj; //Pointer to array contain Adjacency list of vertices
    public:
        Graph(int V); // Graph constructor
        void addEdge(int x, int y); // Add egde to graph
        void calculateDistanceDFS(int vertex, int parent);
        int *dis; // Pointer to array containing distance of vertices from festive cities
};


Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; // Allocating memory to adjacency lists of vertices
    dis = new int[V]; // Allocating memory to Distance array of vertices
    for(int i = 0; i < V; i++) 
        dis[i] = -1; // Initializing distances of all vertices
}

void Graph::addEdge(int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void Graph::calculateDistanceDFS(int vertex, int parent) {
    
    list<int>::iterator it;
    for(it = adj[vertex].begin(); it != adj[vertex].end(); it++) {
        if (*it == parent) {
            continue;
        }
        if (dis[*it] == -1 || dis[*it] > dis[vertex] + 1) { // calulating distance of cities from nearest festive city. 
            dis[*it] = dis[vertex] + 1;
            calculateDistanceDFS(*it, vertex);
        }
    }
}

int main() {
    int n, m, x, y, i; // n is No. of vertices, m is No. of queries 
    scanf("%d%d", &n, &m);

    Graph G(VMAX); // Initialising Graph.

    for( i = 1; i < n; i++ ) {
        scanf("%d%d", &x, &y);
        G.addEdge(x, y); // Adding edge to graph bidirectionally 
    }

    G.dis[1] = 0; // Initially city 1 is festive city.
    G.calculateDistanceDFS(1, 0); // calculating distance of all city from first festive city.
    for(i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        if(x == 1) {
            G.dis[y] = 0;// making city y to festive city
            G.calculateDistanceDFS(y, 0); // calculating distance of all cities from new festive city y.
        } else {
            printf("%d\n", G.dis[y]);
        }
    }
    
    return 0;
    
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>

#define V 100

using namespace std;

static int z;
int y = 9;
void sol() {
    int y;
    static int z;
    z = 5;
    y = 16;
    z++;
    cout<<y<<" "<<z;
    cout<<::y<<::z;
    ::z++;
    cout<<::z;
}
int main() {
    cout<<y<<" "<<z;
    int y,z;
    y =10;
    z = 7;
    cout<<y<<" "<<z;
    sol();
    sol();
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

/*int factorial(int N) {
      if(N < 0) {
        return -1;
    } else {
        int z;
        if(N == 0 || N == 1) return 1;
        else {
        return N* factorial(N-1);
            if(z < 0) return -1;
        }
    }         //return z;
    //}
}*/
/*int factorial(int N) {
    if(N < 0) return -1;
    if(N == 0 || N == 1) return 1;
    long i,result = 1;
    for(i = 2; i <= N; i++) {
        result = result * i;
        if(result > INT_MAX) {
            return -1;
        }
    }
    return (int)result;
}*/
int factorial(int N) {
    if(N < 0) return -1;
    if(N == 0 || N == 1) return 1;
    int i, j, result = 1;
    for(i = 2; i <= N; i++) {
        int y = 0;
        for(j = 0; j < i; j++) {
            y =  y + result;
            //result = result + i;
            if( y > INT_MAX - result) {
                return -1;
            }
        }
        result = y;
    }
    return result;
}
int main() {
    int N;
    scanf("%d",&N);
    int x = factorial(N);
    printf("%d\n%d",x,INT_MAX-1);
    return 0;
}

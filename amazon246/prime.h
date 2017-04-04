#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <stack>
#include <map>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

void SieveOfEratosthenes(int N) {
	bool prime[N+1];
	memset(prime,true,sizeof(prime));

	for(int p = 2; p*p <= N; p++) {
		if(prime[p] == true) {
			for(int i = p*2; i <= N; i += p ) {
				prime[i] = false;
			}
		}
	}
	for(int i = 2; i <= N; i++) {
		if(prime[i] == true) {
			cout<<i<<" ";
		}
	}
}
#endif

//============================================================================
// Name        : dup.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>

#define MAX 1000
using namespace std;
int cmp (const void *a,const void *b ) {
	return ( *(char*)a - *(char*)b );
}
void swap( char *a, char *b ) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int ceil(char *a, char b, int l, int n) {
	int index = l;

	for(int i = l + 1; i <= n; i++ ) {
		if(a[i] > b && a[i] < a[index]) {
			index = i;
		}
	}
	return index;
}
void permutation( char *a, int len) {
	int i = 0;

	while(i != -1) {
		static int x;
		printf("%d %s \n", ++x, a);

		for(i = len - 2; i >= 0; i-- ) {
			if(a[i] < a[i+1])
				break;
		}
		if( i == -1 )
			break;
		else {
			int index = ceil(a,a[i], i+1,len-1);
			swap(&a[i],&a[index]);
			qsort(a+i+1,len - i - 1,sizeof(a[0]),cmp);
		}
	}
}
bool permute(string::iterator first, string::iterator last) {
	if (first == last) return false;
	string::iterator i = last;
	    if (first == --i) return false;

	    while (true) {
	    	string::iterator i1, i2;

	        i1 = i;
	        if (*--i < *i1) {
	            i2 = last;
	            while (!(*i < *--i2))
	                ;
	            std::iter_swap(i, i2);
	            std::reverse(i1, last);
	            return true;
	        }
	        if (i == first) {
	            std::reverse(first, last);
	            return false;
	        }
	    }
}
int main() {
	string st;
	cin>>st;
	char str[MAX];
	scanf("%s", str);
	int len  = strlen(str);
	qsort(str,len, sizeof(str[0]), cmp);
	char *s = new char[st.length()];
	sort(st.begin(),st.end());
	strcpy(s,st.c_str());
	cout<<s<<"\n"<<str;
	vector<string> sp;
	do {
		sp.push_back(st);
		cout<<st<<endl;
	}while(permute(st.begin(),st.end()));
	cout<<endl<<st<<endl;
	for(vector<string>::reverse_iterator it = sp.rbegin(); it != sp.rend(); it++) {
		cout<<*it<<" ";
	}
	permutation(s,strlen(s));
	return 0;
}

//============================================================================
// Name        : stringcoins.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, i, j, k, count = 0, cnt = 0, flag = 0, val = 0;
	cin>>K;
	string s;
	cin>>s;
	map<char,int> mymap;
	map<char,int>::iterator it;
	for(i = 0; i < s.length(); i++ ){
		it = mymap.find(s[i]);
		if(it != mymap.end()) {
			it->second++;
		}else {
			mymap.insert(pair<char,int>(s[i],1));
			cnt++;
		}
	}
	i = 0;
	j = s.length() -1;
	val = cnt;
	//if(cnt == K) count++;
	while(i < s.length() - K ) {
		if(j >= i + K - 1) {
			if(val == K) {
				count++;
			}
			it = mymap.find(s[j]);
			if(it->second == 1) {
				val--;
			}else{
				it->second--;
			}
			//cout<<endl<<"VAL:" <<val<<endl;
			j--;
		}else {
			mymap.clear();
			cnt = 0;
			for(k = i + 1; k < s.length(); k++ ){
					it = mymap.find(s[k]);
					if(it != mymap.end()) {
						it->second++;
					}else {
						mymap.insert(pair<char,int>(s[k],1));
						cnt++;
					}
			}
			/*it = mymap.find(s[i]);
			if(it->second == 1) {
				mymap.erase(it);
				cnt--;
			}else {
				it->second--;
			}*/
			//cout<<"cnt: "<<cnt<<endl;
			val = cnt;
			i++;
			j = s.length() -1;

		}
	}
	cout<<count;
	double x = 13/3;
	cout<<endl<<(float)x;
	printf("\n%f", x);
	return 0;
}

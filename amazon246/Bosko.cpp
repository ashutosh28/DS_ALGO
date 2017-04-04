//============================================================================
// Name        : Bosko.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "test.h"
#include <vector>
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones
const uint64_t hff = 0xffffffffffffffff; //binary: all ones
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...

multimap<const char*,int> mymap;
multimap<const char*,int>::iterator it;
int popcount_1(uint64_t x) {
    x = (x & m1 ) + ((x >>  1) & m1 );
    x = (x & m2 ) + ((x >>  2) & m2 );
    x = (x & m4 ) + ((x >>  4) & m4 );
    x = (x & m8 ) + ((x >>  8) & m8 );
    x = (x & m16) + ((x >> 16) & m16);
    x = (x & m32) + ((x >> 32) & m32);
    return x;
}
int popcount_3(uint64_t x) {
    x -= (x >> 1) & m1;
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;
    return (x * h01)>>56;
}
void swap(char *x,char *y) {
	char temp;
		temp = *x;
		*x = *y;
		*y = temp;
}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r) {
   	   /*it = mymap.find(a);
   	   if(it != mymap.end()) {
   		   it->second++;
   	   }else {*/
     //printf("%s\n", a);
	   //cout<<a<<endl;
   		 /* const char *d = a;
	   mymap.insert(pair<const char*,int>(d,1));
	   }*/
   	   cout<<a<<endl;
	}
   else
   {
       for (i = l; i <= r; i++)
       {
    	   char t = a[l];
    	   a[l] = a[i];
    	   a[i] = t;
    	   /*a[l] = a[l] ^ a[i];
    	   			a[i] = a[l] ^ a[i];
    	   			a[l] = a[l] ^ a[i];*/
    	   			//cout<< a<< endl;
    	   			permute(a,l+1,r);
    	   			t = a[l];
    	   			    	   a[l] = a[i];
    	   			    	   a[i] = t;
    	   			/*a[l] = a[l] ^ a[i];
    	   			a[i] = a[l] ^ a[i];
    	   			a[l] = a[l] ^ a[i];*/
          /*swap(&a[l], &a[i]);
          permute(a, l+1, r);
          swap(&a[l], &a[i]);*/ //backtrack
       }
   }
}
/*void permute(const string &a, int l, int r) {
 * void permute(string &a, int l, int r) {
	cout<<a<<" kl"<<endl;
	static int x;
	if(l == r) {
		cout << "permutation No: " << ++x << " " << a << l<<""<<r<<endl;
	}else {
		for(int i = 1; i <= r; i++ ) {
			char t = a[l];
			    	   a[l] = a[i];
			    	   a[i] = t;
			a[l] = a[l] ^ a[i];
			a[i] = a[l] ^ a[i];
			a[l] = a[l] ^ a[i];
			cout<< a<< endl;
			permute(a,l+1,r);
			t = a[l];
			    	   a[l] = a[i];
			    	   a[i] = t;
			a[l] = a[l] ^ a[i];
			a[i] = a[l] ^ a[i];
			a[l] = a[l] ^ a[i];
		}
	}
}*/
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	std::cout<<"dynamic programming"<<endl;
	string s;
	//cin>>s;
	getline(cin,s);
	char *c = new char[s.length()];
	strcpy(c,s.c_str());
	sort(s.begin(),s.end());
	char *tok = strtok(c," ");
	while(tok != NULL) {
		cout<<tok<<endl;
		tok = strtok(NULL," ");
	}
	for(int i = 0; i < strlen(c); i++ ) {
		cout << "hello" << endl;
	}
	cout<<endl<<s<<endl<<"ab bolo";
	string st;
	cin >> st;
	int N  = st.length();
	for(int i = 0; i < N/2; i++ ) {
		st[i] = st[i] ^ st[N - 1 -i];
		st[N - 1 - i] = st[i] ^ st[N - 1 -i];
		st[i] = st[i] ^ st[N - 1 -i];
	}
	cout << "\n" << st <<endl;

	string str;
	cin>>str;
	sort(str.begin(),str.end());
	cout<<endl<<str<<endl;
	char *cr = new char[str.length()];
	strcpy(cr,str.c_str());
	permute(cr,0,strlen(cr)-1);
	//permute(str,0,str.length() -1);
	int ptr;
	cin>>ptr;
	//cout<<endl<<popcount_3(ptr)<<endl;
	ptr = ptr - ((ptr >> 1) & 0x55555555);
	     ptr = (ptr & 0x33333333) + ((ptr >> 2) & 0x33333333);
	  ptr =     (((ptr + (ptr >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	  cout<<endl<<ptr<<endl;
	  for(it = mymap.begin(); it != mymap.end(); it++ ) {
		  cout<<it->first<< " " << it->second<<endl;
	  }
	  int z[] = {4,5,6};
	  vector<int> X;
	  X.push_back(z[0]);
	  X.push_back(z[1]);
	  X.push_back(z[2]);
	  do {
		  //cout<<str<< " ";
		  for(int i =0; i < X.size(); i++ ){
			  cout<<X[i];
		  }
		  cout<<" ";
	  }while(next_permutation(X.begin(),X.end()));
	  //cout<<*(str.begin())<<endl;
			  reverse(str.begin(),str.end());
			  cout<<str;
	return 0;
}

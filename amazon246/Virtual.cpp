//============================================================================
// Name        : Virtual.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;
class A {//Empty class
	char a;
	int b ;
};

class B {
	int a;
	public:
	void foo() const {
		cout<<"Class B foo";
	}
};
class C {
	public:
	void foo()  const {
		cout<<"Class C foo";
	}
};
class D {
	int a;
	public:
	virtual void foo() const {
		cout<<"Class D foo";
	}
	virtual ~D(){}
};
class E {
	public:
	virtual void foo() const {
		cout<<"Class E foo";
	}
	virtual void add(int &a, int &b, int &sum) {
		sum = a + b;
	}
	virtual ~E(){}
};
class F: public E {
	public:
	void foo() const{}
};
class base {
	public:
	virtual void foo() const = 0;
};
class drived: base {
	virtual void foo() const {
		cout<<endl;
	}
};
static int a = 4;
class alig {
	//int a;
	char b;
	int c;
};
void func() {
	static int a = 3;
	a--;
	cout<<a<<" "<<::a<<endl;
}
int main() {
	func();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout<<"Size of class A "<<sizeof(A)<<endl;
	cout<<"Size of class B "<<sizeof(B)<<endl;
	cout<<"Size of class C "<<sizeof(C)<<endl;
	cout<<"Size of class D "<<sizeof(D)<<endl;
	cout<<"Size of class E "<<sizeof(E)<<endl;
	cout<<"Size of void* and int* "<<sizeof(void*)<<" "<<sizeof(int*)<<endl;
	cout<<"Size of class F "<<sizeof(F)<<endl;
	cout<<sizeof(alig);
	drived x;
	return 0;
}

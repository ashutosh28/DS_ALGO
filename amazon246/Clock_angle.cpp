//============================================================================
// Name        : Clock_angle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class test {

};
struct test1 {

};
class test_drived: public test {

};
double angleBetHrAndMinHand(int hr, int min) {
	double angle;
	double hrangle,minangle;
	if(hr == 12) {
		hr = 0;
	}
	if(min == 60) {
		min = 0;
		hr += 1;
	}
	hrangle = hr*30 + 0.5*(min);
	minangle = min*6;
	angle = abs(hrangle - minangle);
	return angle;
}
int main() {
	int hr,min;
	cout<<"Enter hr and min: ";
	cin>>hr>>min;
	cout<<"Angle is: "<<angleBetHrAndMinHand(hr,min);
	cout<<endl<<sizeof(test)<<endl<<sizeof(test1);
	test t;
	test1 t1;
	cout<<endl<<sizeof(t)<<endl<<sizeof(t1);
	test *t2 = new test();
	test1 *t3 = new test1();
	int *i;
	cout<<endl<<sizeof(t2)<<endl<<sizeof(t3)<<endl<<sizeof(int)<<endl<<sizeof(test_drived);
	return 0;
}

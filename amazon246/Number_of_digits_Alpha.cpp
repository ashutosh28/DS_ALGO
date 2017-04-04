//============================================================================
// Name        : Number_of_digits_&_Alpha.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "numb.h"

int secondLargest(int *A, int N){
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	for(int i = 0; i < N; i++) {
		if(A[i] > max1) {
			max2 = max1;
			max1 = A[i];

		}
		 if(A[i] < max1 && max2 < A[i]) {
			max2 = A[i];
		}
	}
	return max2;
}
int* digitAndAlphaNumbers(string &s){
	int dig = 0, alpha = 0;
	for(int i = 0;i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			dig++;
		}
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			alpha++;
		}
	}
	int *A = new int[2];
	A[0] = dig;
	A[1] = alpha;
	return A;
}
int main() {
	int N;
	cout<<"Enter number of elements in array: ";
	cin>>N;
	int *A = (int*)malloc(N*sizeof(int));
	cout<<"Now enter numbers";
	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	cout<<"Second Largest number in array is: "<<secondLargest(A,N);
	string s;
	cin>>s;
	cout<<"\nSize of string is:"<<s.size();
	int *x = digitAndAlphaNumbers(s);
	cout<<"Number of digits in string is: "<<x[0]<<" and Alphabets are: "<<x[1];

	//delete (A);
	return 0;
}

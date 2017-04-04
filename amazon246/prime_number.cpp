//============================================================================
// Name        : prime_number.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "prime.h"

int main() {
	int N;
	cout<<"Enter Number :";
	cin>>N;
	SieveOfEratosthenes(N);
	return 0;
}

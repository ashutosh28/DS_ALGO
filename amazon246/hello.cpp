//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void FirstandSecondMAX(int *A, int N) {
	int first, second;
	if(N == 0) {
		cout<<"Max values array empty\n";
	}else if(N == 1) {
		cout<<"One one element in array so one maximum" << A[0]<<endl;
	}/*else if(N == 2) {
		if(A[0] > A[1]) {
			first = A[0];
			second = A[1];
		}else {
			first = A[0];
			second = A[1];
		}
		cout<<"Maximum is: "<<first<<" Second Maximum is: "<<second<<endl;
	}*/else {
		first = A[0];
		second = INT_MIN;
		for(int i = 1; i < N; i++ ) {
			if(first < A[i] ) {
				second  = first;
				first = A[i];
			}
			if(A[i] < first && second < A[i]) {
				second = A[i];
			}
			/*if(second < A[i] && first > A[i]) {
				second  = A[i];
			}*/
		}
		int a=1000;
		 int *b = &a;
		 cout<<*++b<<endl;;
		cout<<"Maximum is: "<<first<<" Second Maximum is: "<<second<<endl;
	}
}
int insertlist(int *A, int N, int X);
int main() {
	int N, X;
	cin>>N;
	int A[N];
	for(int i = 0; i < N; i++ ) {
		cin>>A[i];
	}
	//cin>>X;
	//cout<<insertlist(A,N,X);
	FirstandSecondMAX(A,N);

	return 0;
}


int insertlist(int *A, int N, int X) {
	//for(int i = 0; i < N; i++ ){
	int res = -1;
	int l = 0;
	int r = N - 1;
	while(l < r) {
		int m = l + r/2;
		if(A[m] > X) {
			if(X > A[m-1]) { res = m; break;}
			r = m - 1;
		}else if( A[m] < X) {
			if(X < A[m+1]) { res =  m+1; break;}
			l = m + 1;
		}
	}
	if(X < A[0]) res = 1;
	if(X > A[N-1]) res = N;
	return res;
}

/*void mirrorTree(struct Node *Head) {
	if(head == NULL) {
		return ;
	}else {
		struct Node *tmp;
		if(Head->left != NULL) {
			mirrorTree(Head->left);
		}
		if(Head->right != NULL) {
			mirrorTree(Head->right);
		}

		//Swaping
		tmp = Head->left;
		Head->left = Head->right;
		Head->right = tmp;
	}
}*/
















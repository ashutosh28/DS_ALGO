//============================================================================
// Name        : Iterative_height_of_BTree.cpp
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
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node(int v) {
		data = v;
		left = NULL;
		right = NULL;
	}
};
typedef Node node;

int treeHeight(struct Node *root) {
	if(root == NULL) return 0;

	queue<node*> q;
	int height = 0;
	q.push(root);

	while(1) {
		int nodecount = q.size();
		if(nodecount == 0) return height;

		height++;

		while(nodecount > 0) {
			node *front = q.front();
			q.pop();
			if(front->left){
				q.push(front->left);
			}
			if(front->right){
				q.push(front->right);
			}
			nodecount--;
		}
	}
}
int Height(struct Node *root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + max(Height(root->left),Height(root->right));
}
int main() {
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->left->right = new node(7);
	cout<<"Height of tree is: "<<treeHeight(root);
	cout<<endl<<"Recursive Height of tree: "<<Height(root);
}

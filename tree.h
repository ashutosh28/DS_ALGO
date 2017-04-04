#ifndef _tree_h
#define _tree_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Node
{
            T key;
            Node *left;
            Node *right;
};
template <typename T>
class tree
{
    public:
        Node<T> *head;
        tree();
        ~tree();
        void insert(Node<T> **head,T value);
        bool search(Node<T> *head,T value);
        void printTreeInorder(tree &Tr);
        void printTreePreorder(tree &Tr);
        void printTreePostrder(tree &Tr);

    private:
        /*typedef struct Node
        {
            T key;
            Node *left;
            Node *right;
        }Node;*/

        int CountOfTree;
};

#endif

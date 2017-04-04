#ifndef _amazon_h
#define _amazon_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct node {
    int data;
    struct node *next;
    node (int val){ //for C++ user insert with new 
        data = val;
        next = NULL;
    }
};
typedef struct node LNode;
struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
    tnode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
typedef struct node TNode;
void swap(int *a,int*b) { *a = *a ^ *b; *b = *a ^ *b;*a = *a ^ *b;}
void print_matrix(int **mat,int r,int c);
void spiral_print(int **mat,int r,int c);
void transpose_matrix(int **mat,int r,int c);
void multiply(int **mat);
int zeroindex(int *A,int len);

class graph;
class stackArray{
    public:
        stackArray(int size) {
            top =-1;
            len=size;
            A=(int*)malloc(size*sizeof(int));
        }
        void push(int val);
        void pop();
        int topofstack();
        bool isempty();
        bool isfull();
        int stacklength();
        void printstack();
    private:
        int top;
        int *A;
        int len;
        
};
void stackArray::pop() {
    if(stackArray::isempty()) return;
    else {
        top--;
    }
}
bool stackArray::isempty() {
    if(top == -1) return true;
    else return false;
}
bool stackArray::isfull() {
    if(top==len-1) return true;
    else return false;
}
void stackArray::push(int val){
    if(isfull()){ cout<<"\nStack is Full\n"; return ;}
    else{

        A[++top]=val;
    }
}
void stackArray::printstack() {
    int t=top;
    while(t!=-1) {
        cout<<A[t]<<" ";
        t--;
    }
}
int stackArray::stacklength() {
    return top+1;
}

class stackLL{
    public:
        stackLL() {
            top=-1;
            len=0;
            head = NULL;
        }
        int topofstack();
        void push(int val);
        void pop();
        bool isempty();
        //bool isfull();
        void printstack();
    private:
        int top;
        int len;
        struct node *head;
};
int stackLL::topofstack(){
    if(isempty()) return 0 ;
    else {
        return head->data;
    }
}
void stackLL::push(int val) {
    if(head == NULL) {
        //node *temp = (node*)malloc(sizeof(node));
        node *temp =new node(val);
        temp->next =head;
        head = temp;
        len++;
        top++;
    }else {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
        len++;
        top++;
    }
}
void stackLL::pop() {
    if(isempty()) return ;
    else {
        node *temp = head;
        head = head->next;
        len--;
        top--;
        delete(temp);
    }
}
bool stackLL::isempty() {
    if(head == NULL) return true;
    else return false;
}
void stackLL::printstack() {
    node *temp=head;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

class tree{
    private:
        struct tnode *head;
        int height;
    public:
        tree(){
            head = NULL;
            height = 0;
        }
        void insert(int val);
        int remove();
        void inorderrecur();
        void preorderrecur();
        void postorederrecur();
        void inorderiterative();
        void preorderiterative();
        void postorderiterative();
        bool isBST();
        void levelordertraversal();
        void bottomview();
        void zigzaglevelordertraversal();
        void printallpathfromroottoleaf();

};
class queue;
class LinkedListArray;
class heap;
class periorty_queue_min;// public heap;
class periorty_queue_max;//public heap;


#endif


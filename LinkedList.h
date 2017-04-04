#ifndef _LinkedList_h
#define _LinkedList_h

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cmath>
using namespace std;

typedef struct Node
{
	int data;
	string key;
	struct Node *next;
}Node;
class LinkedList
{
	public:
	LinkedList()
	{
	/*	head=(Node*)malloc(sizeof(Node));
		head->data=0;
		head->key="";
		head->next=NULL;
	*/	head=NULL;
		size=0;
		
	}
	~LinkedList()
	{
	//	delete head;
	}	
	struct Node* insert_LL(struct Node **head,int data,string name);
	string Search_name(struct Node *head,int data);
	int length_of_LL(struct Node *head);
	Node *head;
	int size;
};
LinkedList* Merge_two_LL(LinkedList *l1,LinkedList *L2);//based on data sorting.
void Sort_LL(LinkedList *L3);
#endif

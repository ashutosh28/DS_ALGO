#ifndef _array_h
#define _array_h

#include<iostream>
#include<cstdlib>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 100
#define MAX_CHAR 256
/*Templete <class T>
typedef struct Node
{
	T data;
	Node *left;
	Node *right;
};*/

typedef struct HashMapNegativeHandle
{
	int key;
	int value;
}HashMapNegativeHandle;
void exchange(int &a,int &b);
bool HashMapSolution(int arr[],int len,int n);
bool HashMapSolutionWithNegative(int arr[],int len,int n);
int MajorityElement(int arr[],int len);
int BinarySearchWithRotatedSortedArray(int arr[],int start,int end,int n);
void print_array(int arr[],int n);
void Smallest_and_second_smallest(int arr[],int n);
void SSort(int arr[],int n);
void ISort(int arr[],int n);
void BSort();
void MSort();
void QSort(int arr[],int start,int end);
int partition(int arr[],int start,int end);
void HSort();

#endif

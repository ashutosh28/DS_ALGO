#include<iostream>
#include<cmath>
#include<stdio.h>
#include<string>
#include<algorithm>

#define MAX 100
using namespace std;

void Qsort(int arr[],int s,int e);
int partition(int arr[],int l,int r);
void swap(int *a,int *b);
void print_array(int arr[],int len);
int main()
{
	int arr[] = {6,8,2,4,9,1,0};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	Qsort(arr,0,len-1);
	print_array(arr,len);
	return 0;
}
void Qsort(int arr[],int s,int e)
{
	if(s<e)
	{
		int p = partition(arr,s,e);
		Qsort(arr,s,p-1);
		Qsort(arr,p+1,e);
	}
}
int partition(int arr[],int l,int r)
{
	int k=l-1;
	int x= arr[r];
	for(int j=l;j<r;++j)
	{
		if(arr[j]<=x)
		{
			k++;
			swap(&arr[k],&arr[j]);
		}
	}
	swap(&arr[k+1],&arr[r]);
	return k+1;
}
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void print_array(int arr[],int len)
{
	if(len>=1)
	{
		for(int i=0;i<len;++i)
		{
		cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

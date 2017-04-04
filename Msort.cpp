#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
#define MAX 100

void merge(int arr[],int s,int mid,int e)
{
	int temp[e-s+1];
	int n1=mid-s;
	int i=0,k=0;
	int j=n1+1;
	while(i<=n1 && j <=e)
	{
		if(arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=n1)
	{
		temp[k++]=arr[i++];
	}
	while(j<=e)
	{
		temp[k++]=arr[j++];
	}
	for(i=0;i<e-s+1;++i)
	{
		arr[i]=temp[i];
	}
}
void Msort(int arr[],int s,int e)
{
	if(s<e)
	{
		int mid = (e+s)/2;
		Msort(arr,s,mid);
		Msort(arr,mid+1,e);
		merge(arr,s,mid,e);
	}
}
void print_array(int arr[],int len)
{
	if(len<=1)
	{
		return;
	}
	else
	{
		for(int i=0;i<len;++i)
		{
			cout<<arr[i]<<" ";
		}
	}
	return;
}
int main()
{
	int arr[] = {2,9,1,8,3,5,4};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	Msort(arr,0,len-1);
	print_array(arr,len);
	return 0;
}

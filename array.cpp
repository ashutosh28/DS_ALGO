#include "array.h"
#include<map>
int main()
{
	int arr[] = {6,7,8,1,2,3,4,5};
	int n;
	size_t len = sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter Sum of pair: ";
	cin>>n;
	if(HashMapSolutionWithNegative(arr,len,n))
	{
		cout<<"Array Contain Elements!"<<endl;
	}
	else
	{
		cout<<"Array doesn't conatain Elements!"<<endl;
	}
	int j=MajorityElement(arr,len);
	cout<<"\n Majority Element is: "<< j<<endl;
	int number=BinarySearchWithRotatedSortedArray(arr,0,len-1,n);
	cout<<"\n Number searched was: "<<number<<endl;
	//ISort(arr,len);
	//SSort(arr,len);
	print_array(arr,len);
	Smallest_and_second_smallest(arr,n);
	QSort(arr,0,n-1);
	print_array(arr,len);
	return 0;
}
bool HashMapSolution(int arr[],int len,int n)
{
	if(len<=1)
	{
		return false;
	}
	int HashMap[MAX];
	int i;
	for(i=0;i<MAX;++i)
	{
		HashMap[i]=-1;
	}
	for(i=0;i<len;++i)
	{
		HashMap[arr[i]]=1;
		
	}	
	for(i=0;i<len;++i)
	{
		if(HashMap[n-arr[i]]== 1)
		{
			return true;
		}
	}
	return false;
}
bool HashMapSolutionWithNegative(int arr[],int len,int n)
{
	if(len<=1)
	{
		return false;
	}
	/*HashMapNegativeHandle HashMap[MAX];
	int i;g
	for(i=0;i<MAX;++i)
	{
		HashMap[i].key=0;
		HashMap[i].value=-1;
	}
	for(i=0;i<len;++i)
	{
		HashMap[arr[i]].key=arr[i];
		HashMap[arr[i]].value=1;
	}
	for(i=0;i<len;++i)
	{
		if(HashMap[n-arr[i]].value==1)
		{
			return true;
		}
	}
	return false;*/
	map<int,int> HashMap;
	int i;
	for(i=0;i<len;i++)
	{
		HashMap[arr[i]]=1;
	}
	for(i=0;i<len;++i)
	{
		if(HashMap[n-arr[i]] == 1)
		{
			return true;
		}
	}
	return false;

}
void exchange(int &a,int &b)
{
	a=a^b;//int temp=a;//a=a+b;
	b=a^b;//a=b;//b=a-b;
	a=a^b;//b=temp;//a=a-b;
}
void exchange(int *a,int *b)
{
	int temp=*a;//a=a+b;
	*b=*a;//a=b;//b=a-b;
	*b=temp;//b=temp;//a=a-b;
}
int MajorityElement(int arr[],int len)
{
	if(len<=0)
	{
		return 0;
	}
	map<int,int> Majority;
	int i,MAX_FRE=0,temp;
	for(i=0;i<len;++i)
	{
		Majority[arr[i]]=0;
	}
	for(i=0;i<len;++i)
	{
		Majority[arr[i]]+=1;
	}
	for(i=0;i<=len;++i)
	{
		if(MAX_FRE<Majority[arr[i]])
		{
			temp=arr[i];
			MAX_FRE=Majority[arr[i]];
		}
	}
	for(i=0;i<len;++i)
	{
		if(arr[i]==temp)
		{
			cout<<"\n NUMBER with frequency: " << arr[i]<<" "<<MAX_FRE<<endl;
			return temp;
		}
	}
	return 0;
}
int BinarySearchWithRotatedSortedArray(int arr[],int start,int end,int n)
{
	if(start<=end)
	{
		int mid=(start+end)/2;
		if(n==arr[mid])
		{
			return arr[mid];
		}
		if(arr[start]<=arr[mid])
		{
			if(n>arr[start] && n<arr[mid])
			{
				return BinarySearchWithRotatedSortedArray(arr,start,mid-1,n);
			}
				return BinarySearchWithRotatedSortedArray(arr,mid+1,end,n);
		}

			if(n<=arr[end] && n>=arr[mid])
				return BinarySearchWithRotatedSortedArray(arr,mid+1,end,n);
				return BinarySearchWithRotatedSortedArray(arr,start,mid-1,n);
			
		}
	else
	{
		return 0;
	}
	return 0;
}
void SSort(int arr[],int n)
{
	if(n<=1)
	{
		return;
	}
	else
	{
		int count=0;
		for(int i=n-1;i>0;--i)
		{
			/*for(int j=i-1;j>=0;j--)
			{
				if(arr[i]<arr[j])
				{
					exchange(&arr[i],&arr[j]);
					count++;
				}
			}*/
			for(int j=i-1;j>=0;--j)
			{
				if(arr[i]<arr[j])
				{
					exchange(&arr[i],&arr[j]);
					count++;
				}
			}
			cout<<"\n Count: "<<count<<endl;
			
		}
		print_array(arr,n);
	}
	return;
}
void ISort(int arr[],int n)
{
	int count=0;
	if(n<=1)
	{
		return;
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;--j)
			{
				if(arr[j]>arr[i])
				{
					exchange(&arr[i],&arr[j]);
					count++;
				}
			}
			cout<<" count : "<<count<<endl;;
		}
	}
	return;
}		
void print_array(int arr[],int n)
{
	if(n<=0)
	{
		cout<<"\nArray is empty"<<endl;
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}
void Smallest_and_second_smallest(int arr[],int n)
{
	if(n<=1)
		return;
	else
	{
		int min=100,Smin=100;
		/*if(arr[0]<arr[1])
		{
			min=arr[0];Smin=arr[1];
		}
		else
		{
			min=arr[1];Smin=arr[0];
		}*/
		for(int i=0;i<n;++i)
		{
			if(arr[i]<min)
			{
				min=arr[i];
				Smin=min;
			}
			else if(arr[i]<Smin && arr[i]!=min)
			{
					Smin=arr[i];
			}
		}
	
		cout<<"\n Min is: "<<min<<" Second Min: "<<Smin<<endl;
	}
	return;
}
void QSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int p =partition(arr,start,end);
		QSort(arr,start,p-1);
		QSort(arr,p+1,end);
	}
}
int partition(int arr[],int start,int end)
{
	if(start<end)
	{
		int l=start-1;
		int x=arr[end];
		int p=start;
		for(int i=p;i<=end-1;i++)
		{
			if(arr[p]<=x)
			{
			l++;
			exchange(&arr[l],&arr[p]);
			}
		}
		exchange(&arr[l+1],&arr[end]);
		return l+1;
	}
	else
		return arr[start];
}


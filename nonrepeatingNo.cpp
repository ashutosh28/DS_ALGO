#include "array.h"
#include<stdlib.h>
int main()
{
	int arr[] = {2,5,8,9,5,8,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	int sum =0;
	for(int i=0;i<len;i++)
	{
		sum = sum ^ arr[i];
	}
	std::cout<<"Non repeating Number in List: "<<sum;
	return 0;
}

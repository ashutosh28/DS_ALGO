#include<iostream>
using namespace std;
int main()
{
	double Dist;
	cout<<"Enter distance in meters: ";
	cin>>Dist;
	double inches=(Dist*10000)/254;
	if(inches<12)
	{
		cout<<"Inches "<<inches<<" only"<<endl;
	}
	else
	{
		int x= inches/12;
		double y= inches -x*12;
		cout<<"Foot "<<x<<" and Inches "<<y<<endl;
	}
	return 0;
}

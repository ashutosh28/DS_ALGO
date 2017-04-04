#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int Temp_in_celsius;
	cout<<"Enter temprature in degree celsius";
	cin>>Temp_in_celsius;
	double Fah=(9*Temp_in_celsius +160)/5;
	cout<<"\nTemprature in degree Fahrenheit: "<<Fah<<endl;
	return 0;
}

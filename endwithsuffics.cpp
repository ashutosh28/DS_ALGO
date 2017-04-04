#include "endwithsuffics.h"

bool endsWith(string str,string suffix,size_t length,size_t suflen);
string trim_str(string str);
string sub_str(string str,int pos,int n);
int main()
{
	int pos,n;
	string str,suffix,str1,str2,str3,str4;
	size_t length=getline(cin,str);
	cout<<"str.lenght():::"<<length<<" and calculated length with function:::"<< str.length()<<endl;
	getline(cin,suffix);
	//cin>>suffix;
	size_t sufflength=suffix.length();
	cout<<"Suffix containing string : " << endsWith(str,suffix,str.length(),suffix.length())<<endl;
	std::cout<<"Keku chutiya hai!!!"<<endl;
	cout<<"Trimmed string: "<<trim_str(str)<<endl;
	cout<<"Enter starting position of sub_str and no of characters in substr:  ";
	cin>>pos>>n;
	cout<<"Sub_str is: " <<sub_str(str,pos,n)<<endl;
	cout<<"Enter isomorphic strings: s1 and s2: ";
	//getline(cin,str1);
	//getline(cin,str2);
	cin>>str1>>str2;
	cout<<"Is s1 and s2 are isomorphic : "<<Isomorphic(str1,str2)<<endl;
	cout<<"Enter rotated two string s3 and s4 ";
	cin>>str3>>str4;
	cout<<"String is rotation of other : "<<rotation(str3,str4)<<endl;
	cout<<"Reverse of string s3 and s4: ";
	reverse_recursion(str3,0);
	cout<<endl<<reverse(str4)<<endl;
	return 0;
}
bool endsWith(string str,string suffix,size_t length,size_t suflen)
{
	if(suflen>length)
	{
		return false;//suffix length greater than string length
	}else
	{
		for(int i=0;i<suflen;++i)
		{
			if(str[length-1-i] != suffix[suflen-1-i])
			{
				return false;
			}
		}
		return true;
	}
}
string trim_str(string str)
{
	string trv = "";
	if(str.length() <=0)
		return str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i] != ' ')
		{
			trv +=str[i];
		}
	}
	cout<<"Length of trimed string :: "<<trv.length()<<endl;
	return trv;
}
string sub_str(string str,int pos,int n)
{
	string sub="";
	size_t len = str.length();
	if(pos<0 || n<=0)
		error("Invalid position and numbers");
	if(pos > len)
		error("Invalid Position");
	if(n > len-pos)
	{
		for(int i=pos;i<len;i++)
		{
			sub +=str[i];
		}
	}else{
		for(int i=0;i<n;i++)
		{
			sub += str[pos+i];
		}
	}
	return sub;
}	
void error(string msg)
{
	cerr<<msg<<endl;
	exit(EXIT_FAILURE);
}
bool Isomorphic(string str1,string str2)
{
	size_t str1len = str1.length();
	size_t str2len = str2.length();
	if(str1len != str2len)//for isomorphic strings length should be equal.
	{
		cout<<"length not matched"<<endl;
		return false;
	}
	else
	{
		int hashofstr1[MAX_CHAR];
		int hashofstr2[MAX_CHAR];
		for(int i=0;i<MAX_CHAR;i++)
		{
			hashofstr1[i]=-1;
			hashofstr2[i]=false;
		}
		for(int i=0;i<str1len;i++)
		{
			if(hashofstr1[str1[i]] == -1)
			{
				if(hashofstr2[str2[i]] == true)
				{
					cout<<"already used in str2"<<endl;
					return false;
				}
				hashofstr2[str2[i]] = true;

				hashofstr1[str1[i]] = str2[i];
			}
			else
			{
				if(hashofstr1[str1[i]] != str2[i])
				{
					return false;
				}
			}
		}
		return true;
	}
}
bool rotation(string str1,string str2)
{
	if(str1.length() != str2.length())
	{
		return false;
	}
	else
	{
		size_t len = str1.length();
		int i,temp=0;
		for(i=0;i<len;i++)
		{
			if(str1[0] == str2[i])
			{
				temp=1;
				break;
			}
		}
		if(!temp)
		{
			return false;
		}
		else
		{
			for(int j=0;j<len;j++)
			{
				if(str1[j] != str2[(i+j)%len])
				{
					return false;
				}	
			}	
		}
	}
	return true;
}
string reverse(const string &str)
{
	if(str.length() <=1)
		return str;
	else
	{
		string temp=str;
		for(int i=0;i<str.length()/2;i++)
		{
			swap(temp[i],temp[str.length()-1-i]);
			//temp[i]=str[str.lenth() -1-i];
		}
		return temp;
	}
}
void reverse_recursion(string str,int i)
{
	if(str[i])
	{
		reverse_recursion(str,i+1);
		cout<<"string reverse : "<<str[i]<<endl;
	}
	else
	{
		return;
	}
}
				
		
		


		
	

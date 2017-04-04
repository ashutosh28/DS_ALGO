#ifndef _endwithsuffice_h
#define _endwithsuffice_h

#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define MAX_CHAR 256
void error(std::string msg);
bool Isomorphic(string str1,string str2);
bool rotation(string str1,string str2);
void reverse_recursion(string str,int i);
string reverse(const string &str);
#endif


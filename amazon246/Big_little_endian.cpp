//============================================================================
// Name        : Big_little_endian.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "biglittleendian.h"

int main() {
	unsigned int i = 0x1234567;
	char *c = (char*)&i;
	for(int x = 0; x < sizeof(i); x++) {

		printf("%.2x",c[x]);
	}
	if(*c) cout<<"Little"<<endl;
	else cout<<"BIG"<<endl;
	cout<<*c<<endl;
	int b1,b2,b3,b4, res;
	b1 = (i & 0x000000ff) << 24;
	b2 = (i & 0x0000ff00) << 8;
	b3 = (i & 0x00ff0000) >> 8;
	b4 = (i & 0xff000000) >> 24;
	res = b1|b2|b3|b4;
	char *s = (char*)&res;
	for(int y = 0; y < sizeof(res); y++) {
		printf("%.2x",s[y]);
	}
	return 0;
}

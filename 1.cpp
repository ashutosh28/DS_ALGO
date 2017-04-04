#include <iostream>

using namespace std;


 struct sec {
     int a;
     char b;
 };
int main()

{

    //int const p = 5;
   // float i = 123.0f;
   // cout<<i<<endl;
    //return 0;
    /*
    cout << ++p;

    return 0;*/
    /*int x = 1;
    x = x<<7;
    x = x>>7;
    cout<<x;*/
    struct sec s = {25,50};
    struct sec *p = (struct sec*)&s;
    cout<<p->a<<p->b;
    return 0;

}

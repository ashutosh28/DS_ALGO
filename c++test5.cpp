#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#define nm(x,y) x
using namespace std;
void fun()
{
#undef i 
#define i 30 
}
class Example{
    public: int a,b,c;
            Example(){a=b=c=1;} //Constructor 1
            Example(int a){a = a; b = c = 1;} //Constructor 2
            Example(int a,int b){a = a; b = b; c = 1;} //Constructor 3
            Example(int a,int b,int c){ a = a; b = b; c = c;
            cout<<"Ashu"<<endl;} //Constructor 4
};
class test {
    public:
        static int n;
        test () { n++; };
        ~test () { n--; };
};
int test::n = 0;
class square
{
    public:
        double side1;
        double area1()
        {
            return(side1*side1);
        }
};
typedef struct{}x2;
int main(){
    double area1=0;
    square c1,c2;
    cout << "Enter the length of the square" << endl;
    cin >> c1.side1;
    cout << "The area of the square is : " << c1.area1() << endl;
    nm(3,5);
    /*test a;
    test b[5];
    test * c = new test;
    cout << a.n << endl;
    delete c;
    cout << test::n << endl;
    Example *obj = new Example (1,2,3.3);*/
    int z,x=5,y=-10,a=4,b=2;
    z = x++ - --y * b / a;
    cout<<endl<<z<<endl;
    char str ='Z';
    printf("\n%c",str);
    int op = 2*3+4*5;
    cout<<endl<<op<<endl;
    struct
    {
        int x;
    }abc;
    (*abc)->x=10;
    printf("%d",abc.x);
    return 0;
}

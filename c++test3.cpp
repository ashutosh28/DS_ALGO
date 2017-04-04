#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

class Base {
    public:
        void f() {
            cout<<"Base\n";
        }
};
class Drived:public Base {
    public:
        void f() {
            cout<<"Drived\n";
        }
};
int x = 5;
class abc { 
       void f();
          void g();
             int x;
};
class abcd { 

       public: 
                 int i; 

                       abcd(int i) { 
                                    i = i;
                                          }
};

int& f() {
        return x;
}
/*void f(int x) {

}

int f(signed x) { 
          return 1;
}*/
int main() {
    /*typedef std::list<int> L;
    L l(5);

    typedef L::const_iterator CI;
    CI cb = l.begin(), ce = l.end();
    typedef L::iterator I;
    I b = l.begin();
    std::transform(cb, --ce, ++b, [ ] (CI::value_type n)  return ++n; );
    std::copy(l.begin(), l.end(), std::ostream_iterator<CI::value_type>(std::cout));
    std::cout<<std::endl;
    return 0;*/
    /*int i = 1, j = 2, k = 3, r;
    r = (i,j,k);
    cout<<r<<endl;
    char s[] = "C++";
    cout<<s<<" ";
    s++;
    cout<<s<<" "<<endl;*/
    /*int i = 5;
    if(i==5) {
        if(i==5) break;
        cout<<"hello";
    }
    cout<<"Hi";*/
    /*Drived obj;
    obj.Base::f();*/
    /*const int a =5;
    a++;
    cout<<a;*/
    /*f() = 10;
    cout<<x<<endl;
    char s[]="Hello\0Hi";
       
       cout<<strlen(s)<<" "<<sizeof(s)<<endl;
       int a[] = {10, 20, 30};
          
        cout<<*a+1;*/
    class student
           { 
               public:  int rno = 10;
                        } v;
      
       cout<<v.rno<<endl;
       char s[] = "Fine";
        *s = 'N';
           
               cout<<s<<endl;
               union abc { 
                         char a, b, c, d, e, f, g, h; 
                               
                               int i;
                                     };
                     cout<<sizeof(abc)<<endl;
                     int a[] = {1, 2}, *p = a;
                        
                           cout<<p[1]<<" "<<sizeof(abc)<<endl;

        int *px = new int; 
           delete px; 
              //delete px; 
                    cout<<"Done"<<endl;

    int i;
       
       char sok[] = "hello";

          for(i=0; sok[i]; ++i);
                cout<<i<<endl;

                   i=0; 
                      
                      while(sok[i++]);
          cout<<i<<endl;
    abcd m(5);
    cout<<m.i<<endl;
    return 0;
}

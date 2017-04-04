#include <iostream>
#include <ctime>
using namespace std;
void f() {
        static int i = 3;
           
            cout<<i;
                if(--i) f();
}
class abcd { 

       public: 
                 int i; 

                       abcd(int i) { 
                                    i = i;
                                          }
};
int main() {
    f();
    int r, x = 2;
       
       float y = 5;
         
          //r = y%x;
             cout<<endl<<r<<endl;
             short unsigned int i = 0; 
                
                cout<<i--<<endl;
                int t = 2;
                    
                    switch(t)
                            {
                                        case 2: cout<<"Hi";
                                                        default: cout<<"Hello";
                                                                    }
        union abc {
                    int x;
                            char ch;
                                } var;
            
                var.ch = 'A';
                        cout<<var.x<<endl;
                        abcd m(5);
                        cout<<m.i<<endl<<time(NULL);

    char CH[15];double prie = 7,897.90;
    //CH[] = "Ashutosh";
    return 0;
}

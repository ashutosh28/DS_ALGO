#include <iostream>
#include <thread>
using namespace std;
void hello(){
    cout<<"hello"<<endl;
}
int main(){
    thread t(hello);
    cout<<"Ashutosh"<<endl;
    t.join();
    return 0;
}

    

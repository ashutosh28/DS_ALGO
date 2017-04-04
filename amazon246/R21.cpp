#include "amazon.h"

int main() {
    int N;
    cout<<"Enter number of element maximum a stack can acquire: ";
    cin>>N;
    stackLL s;
    s.push(3);
    s.push(4);
    s.push(80);
    s.push(7);
    s.printstack();
    cout<<"\ntop of stack: "<<s.topofstack()<<endl;
    s.pop();
    s.pop();
    cout<<"\ntop of stack: "<<s.topofstack()<<endl;

    return 0;
}

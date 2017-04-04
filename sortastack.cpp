#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

void sortstack(stack<int> *s){
    stack<int> s1;
    while(!s->empty()){
        int x = s->top();
        s->pop();
        while(!s1.empty() && x < s1.top()){
            int y = s1.top();
            s1.pop();
            s->push(y);
        }
        s1.push(x);
    }
    while(!s1.empty()){
        int x = s1.top();
        s1.pop();
        s->push(x);
    }

}
void printstack(stack<int> s){
    while(!s.empty()){
        int x = s.top();
        s.pop();
        cout<<x<<" ";
    }
}
int main(){
    int N;
    cout<<"Enter number of elements in Stack: ";
    cin>>N;
    stack<int> s;
    int i,x;
    for(i=0;i<N;i++){
        cin>>x;
        s.push(x);
    }
    sortstack(&s);
    printstack(s);
    return 0;
}

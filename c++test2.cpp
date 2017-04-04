#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class A{
    public:
        A():m_i(0){}
    protected:
        int m_i;
};
class B {
    public:
        B() : m_d(0.0) {}
    protected:
        double m_d;
};
class C : public A, public B {
    public: C(): m_c('a'){}
    private:
            char m_c;
};
int main() {
    C c;
    A *pa = &c;
    B *pb = &c;

    const int x = (pa == &c) ? 1:2;
    const int y  = (pb == &c) ? 3:4;
    const int z = (reinterpret_cast<char*>(pa) == reinterpret_cast<char*>(pb)) ? 5:6;

    cout<<x<<y<<z<<endl;
    return 0;
}

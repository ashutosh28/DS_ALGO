#include <iostream>
using namespace std;
struct s{
    private:
    int a;

};

int main() {
    struct s p;
    p.a = 5;
    cout<<p.a;
    size_t sz = 5;
    while(--sz >= 0) {
        cout<<"hello";
    }
    return 0;
}

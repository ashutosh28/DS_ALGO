#include "array.h"
int DIV(int x, int y)
{
    int n = 0;
    while (x > y) {
        x -= y;
        n++;
    }
    return n; // truncate fraction
}
int main() {
    cout<<DIV(8,3);
    return 0;
}

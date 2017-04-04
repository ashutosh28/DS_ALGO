#include <iostream>
using namespace std;

void rev(char *str) {
        if (*str == '\0') return;
            rev(str++);
                cout << str[0];
}
int main() {
          rev("abcd");
              return 0;
              }

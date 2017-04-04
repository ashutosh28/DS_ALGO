#include "minheap.h"

int main() {
     printf("Including meanheap algorithm");
     int N;
     printf("Please enter number of elements in heap array");
     scanf("%d", &N);

     meanheap<int> mh(N);// = new meanheap(N);

     do {

         char c;
         cout<<"Please enter a character to processed."<<endl;
         int x = mh.getmin();
         cout<<"Min element in heap is: "<<x<<endl;

         cout<<"Do you want to procced further. Y/N";
         cin>>c;
     }while(c == 'Y' || c == 'y');

     return 0;
}

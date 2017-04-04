#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cout<<"Enter the total number of trips: ";
    cin>>N;
    char *pt;
    string p;
    cout<<"\nInput Journey: ";
    //getline(cin,p);
    cin>>p;
    pt = &p[0];
    cout<<pt<<endl;
    int sq[26] = {0};
    int i;
    for(i=0;i<26;i++){
        cout<<sq[0]<<" ";
    }
    return 0;
}
    

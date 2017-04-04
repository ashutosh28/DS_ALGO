#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int Trip,i;
    cout<<"Enter Number of trips: ";
    cin>>Trip;

    string input;
    cout<<"Please enter the valid input journey: ";
    map<char,int> mymap;
    map<char,int>::iterator it;
    char y;
    do{
        y = 'Y';
        cin>>input;
        if(y == 'Y') {
            if(input.size() != (3*Trip + 1)) {
                y = 'N';
            }
        }
        /*if(y == 'Y') {
            i=0;
            while( i <= input.size() - 4 ) {
                if(input[i] == input[i+3] || !(input[i] >= 'A' && input[i] <= 'Z') || !(input[i] >= 'a' && input[i] <= 'z') || input[i+1] != '-' || input[i+2] != '>') {
                    y = 'N';
                    break;
                }
                i = i + 3;
            }
        }*/

        if(y == 'N') {
            cout<<"Invalid Input.\n";
            cout<<"Please re-enter the valid input journey: ";
        }
    }while(y == 'N');
    
    for(i=0;i<input.size();i=i+3) {
        it = mymap.find(input[i]);
        if(it != mymap.end()){
            it->second += 1;
        }else{
            mymap.insert(pair<char,int>(input[i],1));
        }
    }
    int cnt=0;
    for(it = mymap.begin();it != mymap.end();it++) {
        cnt++;
    }
    cout<<"\nThe number of travel loops are: "<<(Trip - cnt + 1)<<endl;
    return 0;
}


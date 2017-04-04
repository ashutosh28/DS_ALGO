#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    string line;
    ifstream myfile("input.txt");
    ofstream myfile1("output.txt");
    map<char*,char*> mymap;
    map<char*,char*>::iterator it;
    if(myfile.is_open()) {
        while( getline(myfile,line) )
        {
            char str[1024]; 
            strcpy(str,line.c_str());
            char *p[4];
            int j=0;
            p[j] = strtok(str,",");
            while(p[j++] != NULL){
                p[j] = strtok(NULL,",");
            }
            j--;
            it = mymap.find(p[j-1]);
            if(it != mymap.end()){
                if(it->second > p[j]){
                    it->second = p[j];
                }
            }else{
                mymap.insert(pair<char*,char*>(p[j-1],p[j]));
            }
        }
        myfile.close();
    }else{
        cout<<"Unable to open file";
    }
    ifstream myfile2("input.txt");
    if( myfile1.is_open() && myfile2.is_open()) {
        while( getline(myfile2,line) ) 
        {
            char str[1024];
            strcpy(str,line.c_str());
            char *p[4];
            int j=0;
            p[j] = strtok(str,",");
            while(p[j++] != NULL){
                p[j] = strtok(NULL,",");
            }
            j--;
            it = mymap.find(p[j-1]);
            if(it != mymap.end()){
                if(it->second > p[j]){
                    myfile1 << p[0] << '\n';
                    cout<<p[0]<<endl;
                }
            }else{
                myfile1<<p[0]<<'\n';
            }
        }
        myfile2.close();
        myfile1.close();
    }else{
        cout<<"Unable to open file";
    }
    return 0;
}


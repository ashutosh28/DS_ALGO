#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void findTriplet(vector<int> a){
        int i,j,k,sum,val=0;
            int N = a.size();
                for(i=0;i<N-2;i++){
                            j = i+1;
                                    k = N-1;
                                            while(j < k){
                                                            if((a[i] + a[j] + a[k]) == 0){
                                                                                val++;k--;
                                                                                            }else if((a[i] + a[j] + a[k]) < 0){
                                                                                                                j++;
                                                                                                                            }else {
                                                                                                                                                k--;
                                                                                                                                                            }
                                                                    }
                                                }
            /*for(i=0;i<N-2;i++){
                for(j=i+1;j<N-1;j++){
                    for(k=j+1;k<N;k++){
                        if(a[i]+a[j]+a[k] == 0)
                            val++;
                    }
                }
            }*/
                    cout<<val;
}
int main() {
        string s;
            getline(cin,s);
                vector<int> v;
                    int i;
                        istringstream ss(s);
                        //replace(s.begin(),s.end(),',',' ');
                        //ss<<s;
                            while(ss>>i){
                                            v.push_back(i);
                                                }
                            int j;
                            for(j=0;j<v.size();j++){
                                cout<<v[j]<<" ";
                            }cout<<endl<<v.size()<<endl;
                                findTriplet(v);
                                    return 0;
}

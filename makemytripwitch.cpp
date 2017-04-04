#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
        int T;
            cin>>T;
                
                while(T--){
                            unsigned long long p,q,r,cnt;
                                    cin>>p>>q>>r;
                                            cnt=0;
                                                    while((q-p !=1) || (r-q != 1)){
                                                                    if((q-p)>(r-q)){
                                                                                        if(q-p != 1){
                                                                                                                r = q;
                                                                                                                                    q = r-1;
                                                                                                                                                        cnt++;
                                                                                                                                                                        }else{
                                                                                                                                                                                                break;
                                                                                                                                                                                                                }
                                                                                                    }else{
                                                                                                                        if(r-q != 1){
                                                                                                                                                p = q;
                                                                                                                                                                    q = r-1;
                                                                                                                                                                                        cnt++;
                                                                                                                                                                                                        }else{
                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                                }
                                                                                                                                    }
                                                                            }
                                                            cout<<cnt<<endl;
                                                                }
                    return 0;
}


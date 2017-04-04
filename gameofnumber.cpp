#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
        long long t,p,q,val=0;
            cin>>t;
                while(t--){
                            cin>>p>>q;
                                    long long i,j;
                                            val=0;
                                                    map<long long,long long> mymap;
                                                            map<long long,long long>::iterator it;
                                                                    /*vector<int> v;
                                                                     *      for(i=p;i<=q;i++){
                                                                     *                  v.push_back(i);
                                                                     *                          }*/
                                                                    for(i=p;i<=q;i++){
                                                                                    mymap.insert(pair<long long,long long>(i,1));
                                                                                                for(j=2;j<=sqrt(q);j++){
                                                                                                                    if(i%(j*j)==0){
                                                                                                                                            it = mymap.find(i);
                                                                                                                                                                if(it!=mymap.end()){
                                                                                                                                                                                            it->second = 0;
                                                                                                                                                                                                                }
                                                                                                                                                                                }
                                                                                                                                }
                                                                                                        }
                                                                            for(it = mymap.begin();it!=mymap.end();it++){
                                                                                            if(it->second == 1) val++;
                                                                                                    }
                                                                                    //val = abs(q-p) + 1;
                                                                                          /*for(i=2;i<=sqrt(q);i++){
                                                                                    //                  for(j=p;j<=q;j++){
                                                                                    //                                  if(j%(i*i)==0){
                                                                                    //                                                      val--;
                                                                                    //                                                                      }
                                                                                    //                                                                                  }
                                                                                    //                                                                                          }*/
                                                                                    //                                                                                                  /*for(i=p;i<=q;i++){
                                                                                    //                                                                                                              for(j=0;j<=sqrt(q);j++){
                                                                                    //                                                                                                                              if(i == j*j){
                                                                                    //                                                                                                                                                  val--;
                                                                                    //                                                                                                                                                                  }
                                                                                    //                                                                                                                                                                              }
                                                                                    //                                                                                                                                                                                      }*/
                                                                                                                                                                                                                                                                                  cout<<val<<endl;
                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                          return 0;
                                                                                                                                                                                                                                                                                          }
                                                                                    

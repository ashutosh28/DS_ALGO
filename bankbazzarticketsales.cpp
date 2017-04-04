#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
void solutionforn2(vector<int> v,int k){
    sort(v.begin(),v.end());
    int i=0,j,p=v.size()-1,val=0;
    while(i<k){
        if(v[p]>=v[p-1]){
            val = val + v[p];
            v[p] = v[p] -1;
        }else{
            for(j=p;j>0;j--){
                if(v[j]<v[j-1]){
                    int temp = v[j];
                    v[j] = v[j-1];
                    v[j-1] = temp;
                }
            }
            val = val + v[p];
            v[p] = v[p] -1;
        }
        i++;
    }
    cout<<"Answer: "<<val<<endl;
}
int solutionforrecursion(vector<int> v,int k){
    if(k==0){
        return 0;
    }
    int max=0,i,j;
    for(i=0;i<v.size();i++){
        if(max<v[i]){
            max = v[i];
            j=i;
        }
    }
    v[j] = v[j] -1;
    return max + solutionforrecursion(v,k-1);
}
int main(){

    int N,k;
    cin>>N>>k;
    int total=0,i,j;
    vector<int> v;
    for(i=0;i<N;i++){
        cin>>j;
        v.push_back(j);
        total = total + j;
    }
    if(k>total){
        cout<<"No. of ticket to be sale "<<k<<" are greater than total no. of ticket available "<<total<<endl;
        return 0;
    }
    for(i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    clock_t start,end;
    double cpu_time_used;
    start = clock();
    solutionforn2(v,k);
    //cout<<"Answer: "<<solutionforrecursion(v,k)<<endl;
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"Time taken: "<<cpu_time_used*1000<<endl;
    return 0;
}

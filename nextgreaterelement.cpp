#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Node {
        int val;
        Node* left;

        Node* right;
    public:
        Node(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};
void insert(Node **root,int temp){
    if(*root == NULL){
        Node* tem = new Node(temp);
        *root = tem;
    }
    else if((*root)->val > temp)
    {
        insert(&((*root)->left),temp);
    }else
    {
        insert(&((*root)->right),temp);
    }
}
void inorder(Node *root,vector<int> &v){
    if(root == NULL){
        return;
    }else{
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
}
int main(){
    int N;
    cout<<"Enter No of elements in Array: ";
    cin>>N;
    int A[N];
    int i;
    /*Node* root = NULL, *ptr = NULL;
    for(i=0;i<N;i++){
        cin>>A[i];
        insert(&root,A[i]);
    }
    vector<int> v;
    inorder(root,v);
    vector<int>::iterator it = v.begin();
    for(i=0;i<N;i++){
        it = find(v.begin(),v.end(),A[i]);
        if(it == v.end() -1){
            A[i] = -1;
            break;
        }
        it++;
        A[i] = *it;
    }*/
    map<int,int> mymap;
    map<int,int>::iterator it;
    for(i=0;i<N;i++){
        cin>>A[i];
        mymap.insert(pair<int,int>(A[i],i));
    }
        
    for(i=0;i<N;i++){
        it = mymap.find(A[i]);
        if(it != mymap.end()){
            it++;
            while(it != mymap.end()){
            
            if(it != mymap.end()){
                if(i <= it->second){
                    A[i] = it->first;
                    break;
                }else{
                    A[i] = -1;
                }
            }else{
                A[i] = -1;
            }
            it++;
            }
        }
    }
    for(i=0;i<N;i++){
        cout<<A[i]<<" ";
        
    }
    return 0;
}

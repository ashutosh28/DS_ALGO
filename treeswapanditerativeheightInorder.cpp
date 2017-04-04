#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int a){
        data = a;
        left = NULL;
        right = NULL;
    }
};
/*void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}*/

void inorder(struct node *root){
    node *current = root;
    stack<node*> s;
    int flag=0;
    while(!flag){
        if(current != NULL){
            s.push(current);
            current = current->left;
        }else{
            if(!s.empty()){
                current = s.top();
                cout<<current->data<<" ";
                s.pop();
                current = current->right;
            }else{
                flag=1;
            }
        }
    }
}
node* CreateBinaryTree(int N,int *A,int B[],int index){
    if(index<N){
        int value = B[index];
        {
            node *t = new node(value);
            if(*((A+index*2)+0) != -1){
                t->left = CreateBinaryTree(N,(int*)A,B, *((A+index*2)+0)-1);
            }else{
                t->left = NULL;
            }
            if(*((A+index*2)+1) != -1){
                t->right = CreateBinaryTree(N,(int*)A,B, *((A+index*2)+1)-1);
            }else{
                t->right = NULL;
            }
            return t;
        }
    }else
    return NULL;
}
void print(int *A,int N,int M){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cout<<*((A+i*M)+j)<<" ";
        }
        cout<<endl;
    }
}
int max(int a,int b){ return a>b?a:b;}
/*int height(struct node *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}*/
int height(struct node *root){
    if(root == NULL) return 0;

    queue<node*> q;
    int h = 0;
    q.push(root);
    while(1){
        int cnt = q.size();
        if(cnt == 0) return h;
        h++;
        while(cnt>0){
            node *temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            cnt--;
        }
    }
}

void swaptreeatheight(struct node **root,int x,int h,int l){
    if(*root == NULL) return;
    //int ht = height(*root);
    if((h-l+1)%x == 0){
        node *temp = (*root)->left;
        (*root)->left = (*root)->right;
        (*root)->right = temp;
        swaptreeatheight(&((*root)->left),x,h,l-1);
        swaptreeatheight(&((*root)->right),x,h,l-1);
    }else{
        swaptreeatheight(&((*root)->left),x,h,l-1);
        swaptreeatheight(&((*root)->right),x,h,l-1);
    }
}
int main() {
    int N,i;
    cin>>N;
    int A[N][2],B[N];
    for(i=0;i<N;i++){
        cin>>A[i][0]>>A[i][1];
        B[i] = i+1;
    }
    struct node *root;
    root = CreateBinaryTree(N,(int*)A,B,0);

    int T,x;
    cin>>T;
    int h = height(root);
    while(T--){
        cin>>x;
        swaptreeatheight(&root,x,h,h);
        inorder(root);
        cout<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *link;
    Node() {
        val=0;
        link=NULL;
    }
};

int main() {
    int N;
    cout<<"Enter Number of persons: ";
    cin>>N;
    int count;
    cout<<"\nEnter Count : ";
    cin>>count;
    struct Node *head = NULL,*start = NULL;
    for(int i=1;i<=N;i++) {
        if(head == NULL) {
        struct Node *temp = new Node();
        temp->val = i;
        temp->link = NULL;
        head = temp;
        start = temp;
        }else {
        
            struct Node *temp = new Node();
            temp->val = i;
            temp->link = NULL;
            head->link = temp;
            head = temp;
        }
    }
    head->link = start;
    head = start;

    while(head->link != NULL){
        struct Node *del;
        del = head->link;
        head->link = head->link->link;
        delete(del);
        
        if(head->link != NULL) {
            head = head->link;
        }else {
            break;
        }
    }

    cout<<"\nValue of last soldier is: "<< head->val<<endl;
    return 0;
}

            


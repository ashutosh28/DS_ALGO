#ifndef _LRUchache_h
#define _LRUchache_h
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;

struct Node {
    int val;
    struct Node *next;
    struct Node *pre;
    Node(int data) {
        val = data;
        next = NULL;
        pre = NULL;
    }
};
class stack{
    private:
        int top;

    public:
        void push(int val);
        int pop();
        bool isempty();
        bool isfull();
};
class DLL{
    private:
        Node* head;
        Node* tail;
        int cnt;
    public:
        DLL() {head =NULL; tail=NULL; cnt = 0;}
//        ~DLL();
        Node* add(int data);
        void removeTail();
        void movetohead(Node* n);
        int size(){ return cnt;}
        void print();
};
Node* DLL::add(int data){
    Node* n = new Node(data);
 //   n->val = data;
   // n->next = NULL;
    //n->pre = NULL;

    if(tail == NULL){
        head = n;
        tail = n;
    }else{
        head->next = n;
        n->pre = head;
        head = n;
    }
    cnt++;
    return n;
}
void DLL::removeTail(){
    if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        Node *temp = tail;
        tail = tail->next;
        tail->pre = NULL;
        delete temp;
    }
    cnt--;
}
void DLL::movetohead(Node* n){
    if(head == n)
        return;
    n->next->pre = n->pre;

    if(n->pre != NULL){
        n->pre->next = n->next;
    }else{
        tail = n->next;
    }
    n->pre = head;
    head->next = n;
    n->next = NULL;
    head = n;
}
void DLL::print(){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->pre;
    }
}

class LRU{
    private:
        int lrusize;
        DLL lruorder;
        map<int,Node*> mymap;
    public:
        LRU(int size){
            lrusize = size;
        }
        //~LRU();
        void fetchPage(int page);
};
void LRU::fetchPage(int page){
    map<int,Node*>::iterator it;
    it = mymap.find(page);
    if(it != mymap.end()){
        lruorder.movetohead((Node*)it->second);
    }else{
        if(lruorder.size() == lrusize - 1)
            lruorder.removeTail();
        Node* nd = lruorder.add(page);
        mymap.insert(pair<int,Node*>(page,nd));
    }
    lruorder.print();
}
#endif

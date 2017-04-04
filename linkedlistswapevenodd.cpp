#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <ctime>
#include <algorithm>
 using namespace std;

 struct node {
     int data;
     struct node *next;
 };
void insert(struct node **head, int val) {
    //struct node *temp = *head;
    if(*head == NULL) {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = val;
        temp->next = NULL;
         *head = temp;
    } else {
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        struct node *temp = *head;
        while(temp->next != NULL) {
            temp =  temp->next;
        }
        temp1->data = val;
        temp1->next = NULL;
        temp->next = temp1;
        temp = temp1;
    }/*
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = *head;
    *head = temp;*/
}
void printlist(struct node *head){
    if(head == NULL) {
        cout<<"List is empty";
        return;
    } else {
        struct node *temp = head;
        while(temp->next != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<"->NULL\n";
    }
}
/*struct node* swapevenodd(struct node **head) {
    struct node *res = NULL;
    if(head == NULL) return res;
    if(head->next == NULL) return *head;
    else {
        struct node *prev = NULL;
        struct node *cur = *head;
        struct node *temp = (*head)->next;
        struct node *nextnode  = (*head)->next->next;
        res = *head->next;
        while(cur->next != NULL || cur->next->next) {
            nextnode  = temp->next;
            temp->next = cur;
            cur->next = prev;
            prev->*/
struct node* swapevenodd(struct node *head) {
    if(head == NULL || head->next == NULL)  return head;
    struct node *temp = head->next->next;
    struct node *newhead = head->next;
     head->next->next = head;
     head->next = swapevenodd(temp);
     return newhead;
}

 int main() {
     int N, i, val;
     cout<<"Enter the no of elements in LinkedList: ";
     cin>>N;
     struct node *head = NULL;
     for(i = 0; i < N; i++) {
         cin>>val;
        insert(&head,val);
     }
     head = swapevenodd(head);
     printlist(head);
     return 0;
 }

      

#include "LinkedList.h"

void print_LL(LinkedList *L3)
{
	Node* temp=L3->head;
	while(temp)
	{
		cout<<"Number: "<<temp->data<<" Name: "<<temp->key<<endl;
		temp=temp->next;
	}
}
struct Node* LinkedList::insert_LL(struct Node **head,int data,string key)
{
	struct Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->key=key;
	temp->next=*head;
	*head=temp;
	return *head;
}
int main()
{
	LinkedList *L1[2];
	int j=0;
	while(j<2)
	{
	L1[j]= new LinkedList();
	//cout<< "DATA of LIST: "<<L1[i]->head->data<<endl;
	//cout<<" KEY OF LIST: "<<L1[i]->head->key<<endl;
	//cout<<" Next of List: "<<L1[i]->head->next<<endl;
	cout<<" Size of List: "<<L1[j]->size<<endl;
	int No_of_element;
	cout<<"Enter Number of Element in LinkedList: ";
	cin>>No_of_element;
	cout<<"\nEnter elements  with name: ";
	for(int i=0;i<No_of_element;++i)
	{
		int number;
		string name;
		cin>>number>>name;
		/*if(L1.size == 0)
		{
			L1->head->data = number;
			L1->head->name = name;
			L1.size=1;
		}
		else
		{*/
			L1[j]->head = L1[j]->insert_LL(&L1[j]->head,number,name);
			L1[j]->size++;
			int Len=L1[j]->length_of_LL(L1[j]->head);
			cout<<"size of LinkedList : "<<L1[j]->size<<" length :"<<Len<<endl;
	}
	j++;
	}		
	LinkedList *L3=Merge_two_LL(L1[0],L1[1]);
	print_LL(L3);
	int value;
	cin>>value;
	string str = L3->Search_name(L3->head,value);
	cout<<endl<<"Name of serach number: "<<str<<endl;
	Sort_LL(L3);
	print_LL(L3);
	delete L1[0];
	delete L1[1];
	delete L3;
	return 0;
}
void Sort_LL(LinkedList *L3)
{
	int len = L3->length_of_LL(L3->head);
	Node* temp=L3->head;
	cout<<endl<<" length of LL: "<<len<<" data : "<<temp->data<<endl;
	LinkedList *L1= new LinkedList();
	LinkedList *L2= new LinkedList();
	int i;
	for(i=0;i<=len/2;i++)
	{
		L1->head = L1->insert_LL(&L1->head,temp->data,temp->key);
		temp=temp->next;
	}
	for(i=len/2+1;i<len;i++)
	{
		L2->head = L2->insert_LL(&L2->head,temp->data,temp->key);
		temp=temp->next;
	}
	cout<<"\n L1 length: " <<L1->length_of_LL(L1->head)<<endl;
	cout<<"\n L2 length: " <<L2->length_of_LL(L1->head)<<endl;
	Sort_LL(L1);
	Sort_LL(L2);
	L3=Merge_two_LL(L1,L2);
	delete L2;
	delete L1;
	
}
	
	
/*struct Node* LinkedList::insert_LL(struct Node **head,int data,string key)
{
	struct Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->key=key;
	temp->next=*head;
	*head=temp;
	return *head;
}*/
int LinkedList::length_of_LL(struct Node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}
string LinkedList::Search_name(struct Node *head,int data)
{
	string name;
	while(head)
	{
		if(head->data==data)
			name = head->key;
		head=head->next;
	}
	return name;
}
LinkedList* Merge_two_LL(LinkedList *L1,LinkedList *L2)
{
	LinkedList *L3 = new LinkedList();
	while(L1->head && L2->head)
	{
		if(L1->head->data<L2->head->data)
		{
			L3->head = L3->insert_LL(&L3->head,L1->head->data,L1->head->key);
			L1->head = L1->head->next;
		}
		else if(L1->head->data==L2->head->data)
		{
			L3->head = L3->insert_LL(&L3->head,L1->head->data,L1->head->key);
			L1->head = L1->head->next;
			L2->head = L2->head->next;
		}
		else
		{
			L3->head = L3->insert_LL(&L3->head,L2->head->data,L2->head->key);
			L2->head = L2->head->next;
		}
	}
	while(L1->head)
	{
		L3->head = L3->insert_LL(&L3->head,L1->head->data,L1->head->key);
		L1->head = L1->head->next;
	}
	while(L2->head)
	{
		L3->head = L3->insert_LL(&L3->head,L2->head->data,L2->head->key);
		L2->head = L2->head->next;
	}
	return L3;
}

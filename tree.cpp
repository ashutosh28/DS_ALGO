#include "tree.h"

int main()
{
    tree<int> *Tr = new tree<int>();
    int command;
    char c;
    do
    {
        cout<<"Please Enter an Entry for opration:"<<endl;
        cout<<"Enter 1 for insert an element.\n";
        cout<<"Enter 2 for search/find an element.\n";
        cout<<"Enter 3 for No. of elements in DataStructure.\n";
        cout<<"Enter 4 for Inorder Print.\n";
        cout<<"Enter 5 for Preorder Print.\n";
        cout<<"Enter 6 for Postorder Print.\n";
        cout<<"Else Enter 9 to exit\n";
        cin>>command;
        switch(command)
        {
            
            case 1:
                int value;
                cout<<"Enter a value as key: ";
                cin>>value;
                Tr->insert(&(Tr->head),value);
                break;
            case 2:
                int val1;
                cout<<"Enter a key to search: ";
                cin>>val1;
                Tr->insert(&(Tr->head),val1);
                break;
            case 3:
                //Countoftree
                break;
            case 4:
                //Inorder
                
                break;
            case 5:
                //Preorder
                break;
            case 6:
                //Postorder
                break;
            //case 7:
            //case 8:
            case 9:
                return 0;
            default:
                cout<<"Not a Valid Entry\n";
                break;
        }
        cout<<endl<<"For Again chossing operation enter Y else N: ";
        cin>>c;
    }while(c == 'y' || c == 'Y');
    return 0;
}
template <typename T>
tree<T>::tree()
{
    head=NULL;
    CountOfTree=0;
}

template <typename T>
tree<T>::~tree()
{
}

template <typename T>
void tree<T>::insert(Node<T> **head,T value)
{
    if(*head == NULL)//Making Root intially
    {
        Node<T> *temp = new Node<T>;
        temp->left = NULL;
        temp->right = NULL;
        temp->key = value;
        *head = temp;
        CountOfTree++;
    cout<<"\nInside insert";
    }
    else
    {
    cout<<"\nInside 2 insert";
        if(*(head)->key == value)
        {
            cout<<"\n Value exists in tree already. Element Found."<<endl;
        }
        else if(*(head)->key <value)
        {
            insert(*(head)->right,value);
        }
        else
        {
            insert(*(head)->left,value);
        }
    }
}

        

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node()
    {
        int value=this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout << "Memory of node with value " << value << " is deleted." << endl;
  
    }
};


void insertAtHead(node*&head,int d)
{
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(node*&tail,int d)
{
 node*temp=new node(d);
   tail->next=temp;
   temp->prev=tail;
   tail=temp;
    
}
void insertAtAnyPosition(node*&head,node*&tail,int pos, int d)
{
    if (pos==1)
    {
            insertAtHead(head,d);
            return;

    }

        node* temp=head;
    
        int cnt=1;
        while(cnt<pos-1)
        {
            temp=temp->next;
            cnt++;
        }
        if (temp->next==NULL)
        {
            insertAtTail(tail,d);
            return;
        }
        node*nodeToInsert=new node(d);
        
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;    
}


void deleteAtAnyPosition(node*&head,node*&tail,int pos)
{
    if (pos==1)
    {
       node*temp=head;
       head=temp->next;
       temp->next=NULL;
       delete temp;
       return;
    }

    
    int cnt=1;
    node*prv=NULL;
    node*curr=head;

    while (cnt<pos)
    {
        prv=curr;
        curr=curr->next;
        cnt++;
    }
    if (curr->next==NULL)
    {
        tail=curr->prev;
        cout<<endl<< "tail: "<<tail->data<<endl;
    }
   curr->prev=NULL;
   prv->next=curr->next;
   curr->next=NULL;
   delete curr;
    

    
    
    
}


void print(node*head)
{
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
int main()
{
    node* node1=new node(10);
    
    node*head=node1;
    node*tail=node1;

    

    insertAtHead(head,12);
    insertAtHead(head,122);
    print(head);
    cout<<endl;
    insertAtTail(tail,11);
    print(head);
    cout<<endl;
    insertAtAnyPosition(head,tail,5,232);
    print(head);
    cout<<endl;

    deleteAtAnyPosition(head,tail,5);
    print(head);
    cout<<endl<<head->data<<" "<<tail->data;

    return 0;
}
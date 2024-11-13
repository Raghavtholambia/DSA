#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insertAtAnyPos(node*&head,node*&tail,int pos,int data)
{
    if (pos==1)
    {
        node* temp=new node(data);
        temp->next=head;
        head=temp;
        return;
    }
    int cnt=1;
    node*temp=head;
    while (pos-1>cnt)
    {
        temp=temp->next;
        cnt++;
    }

    if (temp->next==NULL)
    {
        node*nti=new node(data);
        nti->next=temp->next;
        temp->next=nti;
        tail=nti;
        return;
    }
    
    node*nodeToInsert=new node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;


    
}
void print(node*head)
{
    if (head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    return print(head->next);

    
}

void reverseLL(node*&head,node*&tail){
    node*curr=head;
    tail=curr;
    node*prev=NULL;
    node*forward=NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;    
        curr=forward;
    }
    head=prev;
    return;
}


node*krev(node*head,int k)
{
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    int cnt=0;

    if (head==NULL)
    {
        return NULL;
    }
    

    while (cnt<k && curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    if (forward!=NULL)
    {
        head->next=krev(curr,k);
    }
    return prev;
    
}


int main()
{
    node*head=NULL;
    node*tail=NULL;
    insertAtAnyPos(head,tail,1,12);
    insertAtAnyPos(head,tail,1,1);
    insertAtAnyPos(head,tail,1,22);
    insertAtAnyPos(head,tail,3,23);
    insertAtAnyPos(head,tail,5,42);
    print(head);
    cout<<endl<<head->data<<" "<<tail->data<<endl;

    head=krev(head,2);
    print(head);
    cout<<endl<<head->data<<" "<<tail->data<<endl;
   

    return 0;
}
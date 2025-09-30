// clone a given LL such as there is two pointer one is head head and another one is "random" which point towords the random node in LL.

#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *random;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory of node with value " << value << " is deleted." << endl;
    }
};



void insertAtTail(node *&head, node *&tail, int d)
{

    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    tail->next = temp; // Link the new node to the last node
    tail = temp;       // Update the tail pointer to the new node
}

void print(node *head, node *tail)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;
    cout << "random" << tail->random->data << endl;

    cout << endl;
}


// TC:O(n),SC:O(n)
// node*copyNode(node*head)
// {
//     node*temp=head;
//     node*cloneHead=NULL;
//     node*cloneTail=NULL;

//     while (temp!=NULL)
//     {
//         insertAtTail(cloneHead,cloneTail,temp->data);
//         temp=temp->next;
//     }
//     unordered_map<node*,node*> oldToNew;
//     node*oldnode=head;
//     node*cloneNode=cloneHead;

//     while (oldnode!=NULL)
//     {
//         oldToNew[oldnode]=cloneNode;
//         oldnode=oldnode->next;
//         cloneNode=cloneNode->next;
//     }
//     while (oldnode!=NULL)
//     {
//         cloneNode->random=oldToNew[oldnode->random];
//         oldnode=oldnode->next;
//         cloneNode=cloneNode->next;
//     }

//     return cloneHead;
// }

// TC:O(n),SC:O(1)

node *copyNode(node *head)
{
    node*OrignalNode=head;
    node*cloneTail=NULL;
    node*cloneHead=NULL;
    node*temp=head;

//step 1:   coping the LL
    while (temp!=NULL)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
//step2: cloneNodes add between the original nodes
node*cloneNode=cloneHead;
    node* next=NULL;

while (OrignalNode!=NULL && cloneNode!=NULL)
{
    next=OrignalNode->next;
    OrignalNode->next=cloneNode;
    OrignalNode=next;

    next=cloneNode->next;
    cloneNode->next=OrignalNode;
    cloneNode=next;


}

//step3: random pointer copy

temp=head;

while (temp!=NULL)
{
    if (temp->next!=NULL)
    {
        temp->next->random=temp->random ? temp->random->next : temp->random;
    }
    temp=temp->next->next;
}


//step4: revert the changes done in step2

cloneNode=cloneHead;
OrignalNode=head;

while (OrignalNode!=NULL && cloneNode!=NULL)
{
    
    OrignalNode->next=cloneNode->next;
    OrignalNode=OrignalNode->next;

    if(OrignalNode!=NULL)
    cloneNode->next=OrignalNode->next;
    cloneNode=cloneNode->next;


}
return cloneHead;


    
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 66);
    insertAtTail(head, tail, 122);


    cout << endl
         << "New List:" << endl;

    // random pointer implementation
    head->random = head->next;
    tail->random = head;
    head->next->random = head->next->next;
    head->next->next->random = tail;

    print(head, tail);

    cout << "clone LL" << endl;
    node *cloneHead = copyNode(head);
    print(cloneHead, tail);

    return 0;
}


//   Q1  reverse a singly linked list

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory of node with value " << value << " is deleted." << endl;
    }
};

void insertAtHead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;  // Link the new node to the last node
    tail = temp;        // Update the tail pointer to the new node
}

void print(node* head ,node*&tail) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        if (temp->next==NULL)
        {
            tail=temp;
        }
        temp = temp->next;
        
    }
    cout << endl;
    
}

void insertAtAnyPosition(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    node* nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

node* revLL(node*&head ,node*&tail)
{
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;   
       
                         
    }
    return prev;


}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 3, 32);
    insertAtAnyPosition(head, tail, 3, 12);

    cout << endl << "New List:" << endl;
    print(head,tail);

    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;

    cout<<"reversed Linked List"<<endl;
    head=revLL(head,tail);
    print(head,tail);
    
    return 0;
}






//// Q2|     reverse doubly linked list

// #include<iostream>
// using namespace std;


// class node{
//     public:
//     int data;
//     node*prev;
//     node*next;

//     node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//         this->prev=NULL;
//     }
// };

// void inserAtHead(node*&head,int d)
// {
//     node*temp=new node(d);
//     temp->next=head;
//     temp->prev=NULL;
//     head=temp;
//     return;

// }

// void insert(node*&head,node*&tail,int pos,int d)
// {
//     if (pos==1)
//     {
//         inserAtHead(head,d);
//         return;
//     }
//     int cnt=1;
//     node*temp=head;
    
//     while (pos-1>cnt)
//     {
//         temp=temp->next;
//         cnt++;
//     }
//     if (temp->next==NULL)
//     {
//        node*node2inst=new node(d);
//        temp->next=node2inst;
//        node2inst->prev=temp;
//        node2inst->next=NULL;
//        tail=node2inst;
//        return;
//     }
    
//     node*node2inst=new node(d);
//     node2inst->next=temp->next;
//     temp->next->prev=node2inst;
//     temp->next=node2inst;
//     node2inst->prev=temp;
//     return;
    
    
// }

// //     node*prev=NULL;
// //     node*curr=head;
// //     node*forward=NULL;
// //     while (curr!=NULL)
// //     {
// //         forward=curr->next;
// //         curr->next=prev;
// //         prev=curr;
// //         curr=forward;   
       
                         
// //     }


// void reverse(node*&head,node*&tail)
// {
//     tail=head;
//     node*temp=head;
//     node*prev=NULL;
//     node*forward=NULL;
//     while (temp!=NULL)
//     {
//         forward=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=forward;
//     }
//     head=prev;
    
// }


// void print(node*head)
// {
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }cout<<endl;
    
// }


// void middle(node*head)
// {
//     if (head==NULL||head->next==NULL)
//     {
//         cout<<"middle: "<<head->data<<endl;
//         return;
//     }
//     node*slow=head;
//     node*fast=head->next;

//     while (fast!=NULL)
//     {
//         fast=fast->next;
//         slow=slow->next;
//         fast=fast->next;
//     }
//     cout<<"middle: "<<slow->data<<endl;  
// }

// int main()
// {
//     node*head=NULL;
//     node*tail=NULL;

//     insert(head,tail,1,12);
//     insert(head,tail,1,1);
//     insert(head,tail,2,122);
//     insert(head,tail,4,122);
//     insert(head,tail,1,13322);
//     print(head);
//     reverse(head,tail);

//     cout<<head->data<<" "<<tail->data<<endl;
//     print(head);
//     middle(head);
//     cout<<"head: "<<head->data<<" "<<"tail: "<<tail->data<<endl;
//     return 0;
// }





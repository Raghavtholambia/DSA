// 
//   Q1  reverse a singly linked list

// #include<iostream>
// using namespace std;

// class node {
// public:
//     int data;
//     node* next;

//     node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }

//     ~node() {
//         int value = this->data;
//         if (this->next != NULL) {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "Memory of node with value " << value << " is deleted." << endl;
//     }
// };

// void insertAtHead(node*& head, int d) {
//     node* temp = new node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(node*& tail, int d) {
//     node* temp = new node(d);
//     tail->next = temp;  // Link the new node to the last node
//     tail = temp;        // Update the tail pointer to the new node
// }

// void print(node* head ,node*&tail) {
//     node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         if (temp->next==NULL)
//         {
//             tail=temp;
//         }
//         temp = temp->next;
        
//     }
//     cout << endl;
    
// }

// void insertAtAnyPosition(node*& head, node*& tail, int position, int d) {
//     if (position == 1) {
//         insertAtHead(head, d);
//         return;
//     }

//     node* temp = head;
//     int cnt = 1;

//     while (cnt < position - 1) {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL) {
//         insertAtTail(tail, d);
//         return;
//     }

//     node* nodeToInsert = new node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// node* revLL(node*&head ,node*&tail)
// {
//     node*prev=NULL;
//     node*curr=head;
//     node*forward=NULL;
//     while (curr!=NULL)
//     {
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;   
       
                         
//     }
//     return prev;


// }

// int main() {
//     node* node1 = new node(10);
//     node* head = node1;
//     node* tail = node1;
//     insertAtTail(tail, 12);
//     insertAtAnyPosition(head, tail, 2, 62);
//     insertAtAnyPosition(head, tail, 3, 32);
//     insertAtAnyPosition(head, tail, 3, 12);

//     cout << endl << "New List:" << endl;
//     print(head,tail);

//     cout << "Head: " << head->data << " ";
//     cout << "Tail: " << tail->data << endl;

//     cout<<"reversed Linked List"<<endl;
//     head=revLL(head,tail);
//     print(head,tail);
    
//     return 0;
// }



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












                                                                        //imp!   reverse according to k

// #include<iostream>
// using namespace std;

// class node {
// public:
//     int data;
//     node* next;

//     node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }

//     ~node() {
//         int value = this->data;
//         if (this->next != NULL) {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "Memory of node with value " << value << " is deleted." << endl;
//     }
// };

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
//         if (fast!=NULL)
//         {
//              fast=fast->next;
//         }
//         slow=slow->next;
        
//     }
//     cout<<"middle: "<<slow->data<<endl;  
// }
// void insertAtHead(node*& head, int d) {
//     node* temp = new node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(node*& tail, int d) {
//     node* temp = new node(d);
//     tail->next = temp;  // Link the new node to the last node
//     tail = temp;        // Update the tail pointer to the new node
// }

// void print(node* head ,node*&tail) {
//     node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         if (temp->next==NULL)
//         {
//             tail=temp;
//         }
//         temp = temp->next;
        
//     }

//     cout << endl;
//     cout << "Head: " << head->data << " ";
//     cout << "Tail: " << tail->data << endl;
// }

// void insertAtAnyPosition(node*& head, node*& tail, int position, int d) {
//     if (position == 1) {
//         insertAtHead(head, d);
//         return;
//     }

//     node* temp = head;
//     int cnt = 1;

//     while (cnt < position - 1) {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL) {
//         insertAtTail(tail, d);
//         return;
//     }

//     node* nodeToInsert = new node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// node* revLL(node*&head ,node*&tail)
// {
//     node*prev=NULL;
//     node*curr=head;
//     node*forward=NULL;
//     while (curr!=NULL)
//     {
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;   
       
                         
//     }
//     return prev;
// }



// node* revK(node*head,int k)
// {
//     node*temp=head;
//     node*prev=NULL;
//     node*forward=NULL;
    
//     if (head==NULL)
//     {
//         return NULL;
//     }
//     int cnt=0;
//     while (k>cnt && temp!=NULL)
//     {
//         forward=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=forward;
//         cnt++;
//     }
//     if (forward!=NULL)
//     {
//        head->next=revK(forward,k);
//     }
    
    


// return prev;
// }
    
// bool checkCirLL(node*head)
// {
//     if (head==NULL || head->next==NULL)
//     {
//         return true;
//     }
//     node*temp=head;
//     while (temp!=NULL)
//     {
//         if (temp->next==head)
//         {
//             return true;
//         }
//         temp=temp->next;
        
//     }
//     return false;
    
    
// }



// int main() {
//     node* node1 = new node(10);
//     node* head = node1;
//     node* tail = node1;
//     insertAtTail(tail, 12);
//     insertAtAnyPosition(head, tail, 2, 62);
//     insertAtAnyPosition(head, tail, 3, 32);
//     insertAtAnyPosition(head, tail, 2, 39);
//     insertAtAnyPosition(head, tail, 3, 12);

//     cout << endl << "New List:" << endl;
//     print(head,tail);


//     head=revK(head,2);
//     print(head,tail);


//     return 0;
// }










                                                        //chech the LL is circular or not


// #include<iostream>
// using namespace std;

// class node
// {
//     public:
//     int data;
//     node*next;

//     node(int data){
//         this->data=data;
//         this->next=NULL;
//     }
//     ~node()
//     {
//         int value=this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next=NULL;
//         }
//         cout << "Memory of node with value " << value << " is deleted." << endl;
  
//     }
// };

// void insertAtAnPosition(node*&tail,int element,int data)
// {
//     if (tail==NULL)
//     {
//         node*newNode=new node(data);
//         tail=newNode;
//         newNode->next=newNode;
//         return;
//     }
//     node*curr=tail;
//     while (curr->data!=element)
//     {
//         curr=curr->next;
//     }
//     node*temp=new node(data);
//     temp->next=curr->next;
//     curr->next=temp;
// }

// void deleteNode(node*&tail,int value)
// {
//     if (tail==NULL)
//     {
//         cout<<"List is empty"<<endl;
//         return;
//     }
//     node*prev=tail;
//     node*curr=prev->next;

//     while (curr->data!=value)
//     {
//         prev=curr;
//         curr=curr->next;
//     }
//     prev->next=curr->next;
//     curr->next=NULL;
//     delete curr;
    
    
// }


// bool checkCirLL(node*head)
// {
//     if (head==NULL || head->next==NULL)
//     {
//         return true;
//     }
//     node*temp=head;
//     while (temp!=NULL)
//     {
//         if (temp->next==head)
//         {
//             return true;
//         }
//         temp=temp->next;
        
//     }
//     return false;
    
    
// }

// void print(node*tail)
// {
//     node*temp=tail;
//     do
//     {
//         cout<<tail->data<<" ";
//         tail=tail->next;
//     } while (temp!=tail);
//     cout<<endl;
// }

// int main()
// {
//     node*tail=NULL;
//     insertAtAnPosition(tail,3,5);
//     print(tail);
//     insertAtAnPosition(tail,5,4);
//     print(tail);
//     insertAtAnPosition(tail,5,5);
//     print(tail);
    
    
//     if (checkCirLL(tail))
//     {
//         cout<<"is circular"<<endl;
//     }
//     else
//     cout<<"not"<<endl;

//     return 0;
// }                                                        



                                            //imp! is loop is present in LL
#include<iostream>
#include<map>
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

// bool isLoopPresent(node*head)
// {
//     node*temp=head;
//     map<node*,bool> viseted;
//     if (head==NULL)
//     {
//         return true;
//     }
//     while (temp!=NULL)
//     {
//         //cycle is present
//         if (viseted[temp]==true)
//         {
//             cout<<"loop is present on: "<<temp->data<<endl;
//             return true;
//         }
//         viseted[temp]=true;
//         temp=temp->next;
//     }
//     return false;    
// }


bool floydDetectLoop(node*head)
{
    if (head==NULL)
        return false;
    node*fast=head;
    node*slow=head;

    while (fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if (fast==slow)
        {
            cout<<"loop detect on: "<<fast->data<<endl;
            return 1;
        }
        
    }
    return 0;
    
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail, 12);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 3, 32);
    insertAtAnyPosition(head, tail, 3, 12);
    print(head,tail);
    cout<<"head: "<<head->data<<"tail: "<<tail->data<<endl;
    tail->next=head->next;

if (floydDetectLoop(head))
{
    cout<<"loop is present"<<endl;
}
else
cout<<"loop is not present"<<endl;

    
    return 0;
}




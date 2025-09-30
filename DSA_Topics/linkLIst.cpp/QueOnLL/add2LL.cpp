// add to no. represent by LL   ex firstLL: 1,6,3  ,   secondLL: 7,8,3
//         output:       9,4,6

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

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

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp; // Link the new node to the last node
    tail = temp;       // Update the tail pointer to the new node
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtAnyPosition(node *&head, node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void AtTail(node*&head,node*&tail,int val)
{
    node*temp = new node(val);
    if (head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    else
    {
        tail->next=temp;
        tail=temp;
        return;
    }
    
    
}
node *add(node *first, node *second)
{
    int carry=0;
    node*ansTail=NULL;
    node*ansHead=NULL;
        int digit;
    int sum=0;


    while (first!=NULL || second!=NULL ||carry!=0)
    {
        int val1=0,val2=0;
        if (first!=0)
            val1=first->data;
        if (second!=0)
            val2=second->data;
    

        sum=carry+first->data+second->data;
        digit=sum%10;

        AtTail(ansHead,ansTail,digit);
        carry=sum/10;

        first=first->next;
        second=second->next;
        

    }
    return ansHead;




    // while (first!=NULL && second!=NULL)
    // {
    //     sum=carry+first->data+second->data;
    //     digit=sum%10;

    //     AtTail(ansHead,ansTail,digit);
    //     carry=sum/10;

    //     first=first->next;
    //     second=second->next;
        

    // }

    // while (first!=NULL)
    // {
    //     sum=carry+first->data;
    //     digit=sum%10;

    //     AtTail(ansHead,ansTail,digit);
    //     carry=sum/10;
    //     first=first->next;
    //     second=second->next;
    // }
    
    // while (second!=NULL)
    // {
    //     sum=carry+second->data;
    //     digit=sum%10;

    //     AtTail(ansHead,ansTail,digit);
    //     carry=sum/10;
    //     first=first->next;
    //     second=second->next;
    // }
    // return ansHead;
    
    
}

node *addToLL(node *first, node *second)
{
    first = reverse(first);
    second = reverse(second);

    node *ans = add(first, second);
    node*sum=reverse(ans);
}

int main()
{
    node *node1 = new node(1);

    node *head1 = node1;
    node *tail1 = node1;

    insertAtTail(tail1, 3);
    insertAtAnyPosition(head1, tail1, 2, 6);

    cout << endl
         << "first List:" << endl;
    print(head1);

    cout << "Head1: " << head1->data << " ";
    cout << "Tail1: " << tail1->data << endl;

    node *node2 = new node(7);

    node *head2 = node2;
    node *tail2 = node2;

    insertAtTail(tail2, 3);
    insertAtAnyPosition(head2, tail2, 2, 8);

    cout << "secont List:" << endl;
    print(head2);

    cout << "Head2: " << head2->data << " ";
    cout << "Tail2: " << tail2->data << endl;

    node *ans = addToLL(head1, head2);
    cout<<endl<<"Addition is"<<endl;
    print(ans);

    return 0;
}

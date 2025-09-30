                    //sort the LL {0,1,2,2}


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

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
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



                                //first approch

// void sort0s1s2s(node* head)
// {
//     if (head == NULL) return;  // If the list is empty, no sorting is needed

//     // Step 1: Count occurrences of 0s, 1s, and 2s
//     int zeroCount = 0, oneCount = 0, twoCount = 0;
//     node* temp = head;

//     while (temp != NULL)
//     {
//         if (temp->data == 0) zeroCount++;
//         else if (temp->data == 1) oneCount++;
//         else if (temp->data == 2) twoCount++;
//         temp = temp->next;  // Move to the next node
//     }

//     // Step 2: Update the list based on the counts
//     temp = head;  // Reset temp to the start of the list
//     while (temp != NULL)
//     {
//         if (zeroCount > 0)
//         {
        
//             temp->data = 0;
//             zeroCount--;
//         }
//         else if (oneCount > 0)
//         {
//             temp->data = 1;
//             oneCount--;
//         }
//         else
//         {
//             temp->data = 2;
//             twoCount--;
//         }
//         temp = temp->next;  // Move to the next node
//     }
// }



                            //second approch is to make 3 LL one for 0s,1for 1s,1 for 2s


void sort0s1s2s(node*& head, node*& tail) {
    // Create dummy nodes for each list
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;
    
    node* temp = head;

    // Traverse the original list and link nodes to respective lists
    while (temp != NULL) {
        int value = temp->data;

        if (value == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        } else if (value == 1) {
            oneTail->next = temp;
            oneTail = temp;
        } else if (value == 2) {
            twoTail->next = temp;
            twoTail = temp;
        }
        
        temp = temp->next;
    }

    // Connect the three lists
    // Link zero list to one list if it exists, otherwise link to two list
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    // Link one list to two list
    oneTail->next = twoHead->next;
    
    // End of the sorted list
    twoTail->next = NULL;
    
    // Set the head to the start of the zero list
    head = zeroHead->next;

    // Update the tail to the end of the sorted list
    if (twoTail != twoHead) {
        tail = twoTail;
    } else if (oneTail != oneHead) {
        tail = oneTail;
    } else {
        tail = zeroTail;
    }

    // Clean up dummy nodes
    // delete zeroHead;
    // delete oneHead;
    // delete twoHead;
    return;
}





int main() {
    node* node1 = new node(2);
    node* head = node1;
    node* tail = node1;
    insertAtTail(tail, 0);
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 2, 1);
    cout << endl << "New List:" << endl;
    print(head);

    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;

    cout << "sorted LL"<<endl;

    sort0s1s2s(head,tail);
    print(head);
    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;
    return 0;
}

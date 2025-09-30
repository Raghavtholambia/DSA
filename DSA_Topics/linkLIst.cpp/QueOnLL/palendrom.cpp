#include<iostream>
#include<vector>
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

                                            //   check palendrom TC:O(n),SC:O(n)

// bool checkPalendrom(node*head)
// {
//     vector<int> arr;

//     while (head!=NULL)
//     {
//         arr.push_back(head->data);
//         head=head->next;
//     }
//     int s=0,e=arr.size()-1;
//     while (s<=e)
//     {
//         if (arr[s]!=arr[e])
//         {
//             return 0;
//         }
//             s++;
//             e--;
//     }
//     return 1;
// }


                                                            //TC:O(n),SC: O(1)

// Function to find the middle node of the linked list
node* middle(node* head) {
    node* fast = head;
    node* slow = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Function to reverse a linked list
node* rev(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* forward = NULL;
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
bool checkPalindrome(node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // List with 0 or 1 node is palindrome
    }

    // Find middle
    node* mid = middle(head);
    cout << mid->data << endl;

    // Reverse after middle
    node* temp = mid->next;
    mid->next = rev(temp);

    // Compare both halves
    node* head1 = head;
    node* head2 = mid->next; // Start from the node after mid

    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Restore original list
    temp = mid->next;
    mid->next = rev(temp);
    return true;
}

int main() {
    node* node1 = new node(11);
    node* head = node1;
    node* tail = node1;
 

    insertAtTail(tail, 11);
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 2, 62);
    insertAtAnyPosition(head, tail, 2, 2);

    cout << endl << "New List:" << endl;
    print(head);

    cout << "Head: " << head->data << " ";
    cout << "Tail: " << tail->data << endl;


    cout<<"checking palendrom....."<<endl;

    if (checkPalindrome(head))
    {
        cout<<"palendrom"<<endl;
    }
    else
    {
        cout<<"not palendrom"<<endl;
    }
    
    

    return 0;
}

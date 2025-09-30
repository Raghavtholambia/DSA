#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *creation(node *root)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "enter the data in left for" << data << endl;
    root->left = creation(root->left);
    cout << "enter the data in right for" << data << endl;
    root->right = creation(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    cout<<"q printing..."<<endl;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        
    }
}

int main()
{
    node *root = NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root=creation(root);

    levelOrderTraversal(root);
}
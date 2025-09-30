#include <iostream>
using namespace std;

class stack
{
    int size;
    int top;
    int *arr;

public:
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "over Flow" << endl;
        }
    }
    void pop()
    {
        if (top != -1)
            top--;

        else
            cout << "stack underflow" << endl;
    }
    void peek()
    {
        if (top != -1)
            cout << arr[top]<<endl;
        else
            cout << "stack is empty" << endl;
    }
};

int main()
{
    stack s1(5);
    s1.peek();
    s1.push(2);
    s1.push(23);
    s1.push(222);
    s1.peek();
    s1.pop();
    s1.peek();
}
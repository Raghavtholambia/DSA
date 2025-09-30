                    //delete mid of the stack

#include<iostream>
#include<stack>
using namespace std;


void deleteMid(stack<int>&inputStack,int size,int count=0)
{
    if (count==size/2)
    {
        cout<<"mid deleted: "<<inputStack.top()<<endl;
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    deleteMid(inputStack,size,count+1);
    inputStack.push(num);
    
}


int main()
{
    stack<int> inputStack;
    inputStack.push(120);
    inputStack.push(10);
    
    inputStack.push(22);
    inputStack.push(90);
    cout<<"size of stack: "<<inputStack.size()<<endl;
    deleteMid(inputStack,inputStack.size());
    cout<<"size of stack: "<<inputStack.size();
}

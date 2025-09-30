// check the brackets like: 
//(){}[] =>right  
//}[]}{}=>wrong

#include<iostream>
#include<stack>
using namespace std;

bool checkBrackets(string str)
{
    stack<char> s;

    for (int  i = 0; i < str.length(); i++)
    {
        if (str[i]=='['||str[i]=='{'||str[i]=='(')
        {
            s.push(str[i]);
        }
        else
        {
            if (!s.empty())
            {
                if (str[i]==')' && s.top()=='('||str[i]=='}' && s.top()=='{'||str[i]==']' && s.top()=='[')
                {
                    s.pop();
                }
                else
                return false;
            }
            
        else
        return false;
        }
    }
    if (s.empty())
        return true;

    else
        return false;
}

int main()
{
    string str="[{()}]";

    if (checkBrackets(str)) cout<<"true";
    else cout<<"false";
    
    
}

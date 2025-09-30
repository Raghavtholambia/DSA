#include<iostream>
#include<vector>
using namespace std;


void add1(vector<int>&digits){
    if (digits.size()==1 && digits[0]==9)
{
    digits.pop_back();
    digits.push_back(1);
    digits.push_back(0);
   return;
}



if (digits[digits.size()-1]!=9)
{
    digits[digits.size()-1]=digits[digits.size()-1]+1;
}
else{
    digits[digits.size()-2]=digits[digits.size()-2]+1;
    digits[digits.size()-1]=0;
}
 return;
}


int main()
{
vector<int> digits={9};
add1(digits);


for (int i = 0; i < digits.size(); i++)
{
    cout<<digits[i]<<" ";
}


}
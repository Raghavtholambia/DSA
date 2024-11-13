// #include<iostream>
// using namespace std;

// class hello
// {
// private:
// int data;
// public:
//     void setData(int data)
//     {
//         this->data=data;
//     }
//     int getData()
//     {
//         return data;
//     }
// };
// class yo :public hello{

// };



// int main(){
//     hello r;
//     yo y;
//     r.setData(9);
//     y.setData(4);
//     cout<<r.getData() <<endl;
//     cout<<y.getData();
//     return 0;
// }


#include<iostream>
using namespace std;

int expe(int num)
{
    if (num==1)return 1;
    return num*expe(num-1);
    
}
int main(){
    int ans=expe(2);
    cout<<ans;
    return 0;
}
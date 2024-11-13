#include<iostream>
using namespace std;

class hero
{
    public:
    static int time;
};

int hero::time=3;

int main()
{
    hero h;
    cout << hero::time;
}
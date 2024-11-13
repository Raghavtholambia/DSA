#include<bits/stdc++.h>
using namespace std;

class hero
{
    string enemy ="raghav";
    public:
    int health;
    string name;
    int level;
    char setenemy(string a)
     {
        enemy = a;
      }
    string getenemy()
    {
        return enemy;
    }

};

int main()
{
    hero raghav;
    hero *b =new hero;      
    cout <<  "enemy:" << raghav.getenemy();
    raghav.setenemy("Ds");

}    

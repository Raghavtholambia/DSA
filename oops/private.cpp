#include<bits/stdc++.h>

using namespace std;

class hero
{
    private:
    int health;
    char level;
    
    public:
    int gethealth()
    {
        return health;
    }
    void sethealth(int health)
    {
        this->health = health;
    }


};

int main()
{
    int health=654;
    hero raghav;
    raghav.sethealth(90);
    cout << raghav.gethealth();
    

}
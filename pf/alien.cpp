#include <iostream>
#include <vector>

#include <cstdlib> // for system()
#include <ctime> 
using namespace std;


 class Alien
    {
        private:
        int alienhealth;
        int aliendamage;
        public:
            int life;
            int attack;

        void lifeSet(int Hvalue)
        {
        alienhealth = Hvalue;
        life = alienhealth;
        }

        void attackSet(int atk)
        {
            aliendamage = atk;
            attack = aliendamage;
        }

        void showLife()
        {
            cout << "Alien Life : " << life;
        }

        void showdamage()
        {
            cout << "Alien's Damage : " << attack;
        }

    };




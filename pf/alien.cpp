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
        int aliencharge;
        public:
            int life;
            int attack;
            int aCharge;

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
        
        void chargeSet(int charge)
        {
            if (charge < 3)
            {
                int charge = charge + 1;
            }
            
            aliencharge = charge;
            aCharge = aliencharge;
            
        }
        
        void showCharge()
        {   
            cout << "Charges : " << aCharge;
        }
    };




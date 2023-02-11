  #include <iostream>

  using namespace std;
  
  
  class Zombie
    {
    private:
        int zombieHealth;
        int zombieDamage;
    public:
        int life;
        int attack;
        int range;


        void ZlifeSet(int Hvalue)
        {
        zombieHealth = Hvalue;
        life = zombieHealth;
        }

        void ZattackSet(int atk)
        {
            zombieDamage = atk;
            attack = zombieDamage;
        }

        void zombieRange(int range)
        {
            //code for range
        }

        void showZLife()
        {
            cout << "Zombie Life : " << life;
        }

        void showZDamage()
        {
            cout << "Zombie Damage : " << attack;
        }

    };

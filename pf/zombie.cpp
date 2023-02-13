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

        void ZrangeSet(int dist)
        {
            range = dist;
        }

        void zombieRange(int Zrange)
        {
            range = Zrange;
        }

        void showZLife()
        {
            cout << "Zombie Life : " << life;
        }

        void showZDamage()
        {
            cout << "Zombie Damage : " << attack;
        }

        void showRange()
        {
            cout <<"Zombie's range : " << range;
        }

    };

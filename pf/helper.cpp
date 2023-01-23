#include "helper.h"
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
namespace pf
{
    
    const int kRows = 5;
    const int kColumns = 15;
    char kBoard[kRows][kColumns];
    
    class Map
    {
        public:
            int width;
            int height;     
    };

    class Alien
    {
        public:
            int life;
            int attack;
    };

    class Zombie
    {
        public:
            int life;
            int attack;
            int range;
    };

    int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

    int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }

    void BoardEdit()
    {   
        string a ="n";
        while(a =="n")
        {
        cout << "Board Settings" << endl;
        cout << "---------------" << endl;
        cout << "Board Rows : " << kRows << endl;
        cout << "Board Columns : " << kColumns << endl;
        //cout << "Zombie Count : " <<(variable);

        cout << "Do you wish to change the game settings? (y/n/q to return) : ";
        string choice;
        cin >> choice;
        
        if (choice =="y")
        {
            cout << "kys bozo";
        }
        else if (choice == "n")
        {
            cout << "The game will now begin." << endl;
            Pause();
            ClearScreen();
        }
        else if (choice =="q")
        {
            /*code*/
        }
        else
        {
            choice = a;
            cout << "Invalid input, please try again.";
            Pause();
            ClearScreen();
            continue;  
        }
        break;
        }
        
    }
    
    void CreateGameBoard()
    {
    char objects[] = {'v','^','<','>',' ','h','p','r',' ', ' ', ' '};
    int noOfObjects = 11;
        for (int row = 0; row < kRows; ++row)
        for (int col = 0; col < kColumns; ++col)
        {
            int objNo = rand() % noOfObjects;
            kBoard[row][col] = objects[objNo];
        }
    }

    void ShowGameBoard()
    {
        cout << "  _______________________________" << endl;
        cout << " | Player, be ready for battle!  |" << endl;
        cout << " |_______________________________|" << endl;
        cout << "                                  " << endl;
        for (int row = 0; row < kRows; ++row)
        {
            cout << "  +---";
            for (int col = 0;  col < kColumns - 1; ++col)
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            cout << setw(2) << (kRows - row);
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << kBoard[row][col] << " "; //shows the stuff inside the map
            }
            cout << "|";
            cout << endl;
        }
        cout << "  +---";
        for (int j = 0; j < kColumns - 1; ++j)
            {
            cout << "+---";
            }
        cout << "+" << endl;
    }
}
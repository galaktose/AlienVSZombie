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
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << kBoard[row][col] << "|";
            }
            cout << endl;
        }
            
    }
}
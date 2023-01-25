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
    
    int kRows;
    int kColumns;

        
        int row;
        int col;
        int rowMid;
        int colMid;
        vector<vector<char>>map;    


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
        //kufufu kufufu kufufu
        int x;
        int y;
        int z;
        cout << "Change your game settings." << endl;
        cout << "---------------------------" << endl;
        bool choice = true;
        while(choice = true)
        {
        cout << "New Board Rows (1-15) : "; 
        cin >> x;
        if (x % 2 == 1 && x <= 15)
        {
           row = x;
           cout << "Rows have been updated!" << endl;
           break;
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
            continue;
        }
        break;
        
        }
        bool choice2 = true;
        while(choice2 = true)
        {
        cout << "New Board Columns (1-15): "; cin >> y;
         if (y % 2 == 1 && y <= 15)
        {
           col = y;
           cout << "Columns have been updated!" << endl;
           break;
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
            continue;
        }
        }
        //cout << "Zombie Count : "; cin >> z;
        Pause();
        ClearScreen();
    }

    void BoardSettings()
    {   
        string a ="n";
        while(a =="n")
        {
            int defkRows = 5;
            int defkColumns = 15;
            cout << "Board Settings" << endl;
            cout << "---------------" << endl;
            cout << "Board Rows : " << defkRows << endl;
            cout << "Board Columns : " << defkColumns << endl;
            //cout << "Zombie Count : " <<(variable);

            cout << "Do you wish to change the game settings? (y/n/q to return) : ";
            string choice;
            cin >> choice;
            
            if (choice =="y")
            {   
                ClearScreen();
                BoardEdit();
                break;
            }
            else if (choice == "n")
            {   
                row =5;
                col = 15;
                ClearScreen();
                cout << "The game will now begin." << endl;
                Pause();
            }
            else
            {   
                choice = a;
                cout << "Invalid input, please try again." << endl; 
                Pause();
                ClearScreen();
                continue;  
            }
            break;
        }
        
    }
    
    void CreateGameBoard()
    {
    kRows = row;
    kColumns = col;

    char objects[] = {'v','^','<','>',' ','h','p','r',' ', ' ', ' '};
    int noOfObjects = 11; // number of objects in the array

    rowMid = (kRows /2);
    colMid = (kColumns /2); //center of the map

    map.resize(kRows); // create empty rows
    for (int i = 0; i < kRows; ++i)
    {
        map[i].resize(kColumns); // resize each row
    }

    for (int row = 0; row < kRows; ++row)
    {
        for (int col = 0; col < kColumns; ++col)
        {
            if(row == rowMid && col == colMid)
            {
                map[row][col] = 'A';
            }
            else
            {
            int objNo = rand() % noOfObjects; 
            map[row][col] = objects[objNo]; 
            }
        }
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
                cout << map[row][col] << " "; //shows the stuff inside the map
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
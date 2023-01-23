#ifndef PF_HELPER_H
#define PF_HELPER_H
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
    int ClearScreen();
    int Pause();

    void CreateGameBoard();
    void ShowGameBoard();
}


class alienwar
{
private:
    vector<vector<char>> map_;
    int dimX_;
    int dimY_;

public:
    alienwar(int dimX = 11, int dimY = 3);
    void init(int dimX, int dimY);
    void display() const;
    void moveleft();
   
};

alienwar ::alienwar(int dimX, int dimY)
{
    init(dimX, dimY);
}

void alienwar ::init(int dimX, int dimY)  //map creation
{
    dimX_ = dimX;
    dimY_ = dimY;

    char objects[] = {'v','^','<','>',' ','h','p','r',' ', ' ', ' '};
    int noOfObjects = 11; // number of objects in the array

    // creating a 2D dynamic array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    int Xcenter = (dimX_ /2);
    int Ycenter = (dimY_ /2); //center of the map

    // putting random characters and the alien into the array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            if(i == Ycenter && j == Xcenter)
            {
                map_[i][j] = 'A';
            }
            else
            {
            int objNo = rand() % noOfObjects; //picks a random object from objects[]
            map_[i][j] = objects[objNo];
            }
        }
    }
}

void alienwar::display() const
{
    system("cls"); //idk
    cout << "  _______________________________" << endl;
    cout << " | Player, be ready for battle!  |" << endl;
    cout << " |_______________________________|" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "---";
        }
        cout << "-+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "| " << map_[i][j];
        }
        cout << "|" ;
        cout<< "D" << endl;
            }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+--";
    }
    cout << "+" << endl;
    // display column number
    cout << "   ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10; //for > 10 numbers
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
            cout <<" ";
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "  " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void alienwar:: moveleft()
{
// go on try doing it
}

void tobattle()
{
    alienwar alienwar;
    alienwar.display();
}

#endif
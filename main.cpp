// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: WAN MUHAMMAD ATIF BIN TARAM SATIRAKSA| NOOR HANNAN BIN NOOR HAMSURUDDIN |
// IDs: 1211103154 | 1211104293 |
// Emails: 1211103154@student.mmu.edu.my | 1211104293@student.mmu.edu.my |
// Phones: 011-10255127 | 011-10030429 |
// *********************************************************

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.h"
#include "pf/helper.cpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "Assignment (Part 2)" << endl;
    cout << "Let's Get Started!" << endl;
    while (bool restart = true)
    {
        pf::Pause();
        pf::BoardSettings();
        srand(time(NULL));
        pf::CreateGameBoard();
        pf::ShowGameBoard();
        pf::Pause();
        pf::zombieTurn();
        pf::Pause();
        pf::trailReset();
        pf::activeBoard();
        cout << "Do you want to play again? y/n:" << endl;
        char again;
        cin >> again;
        if (again == 'y')
        {
            cout <<"Here we go again!" << endl;
            continue;
        }
        else if(again == 'N')
        {
            cout <<"Alright! Have a nice day." << endl;
            break;
        }
        else
        {
            cout << "Invalid argument. Returning to settings menu." << endl;
            continue;
        }
        
    }
}

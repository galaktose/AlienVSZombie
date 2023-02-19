#include "helper.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <ostream>
#include <numeric>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include "alien.cpp"
#include "zombie.cpp"
using namespace std;
namespace pf
{
    int charge;
    int kRows;
    int kColumns;
    int rowZom;
    int colZom;
    int HP;
    int dmg;
    int zHP;
    int zDmg;
    int zRange;
    int HPlimit;
    int zDmgLimit;
    int zRangeLimit;

    int row; // up down size
    int rowborder;
    int col; // left right size
    int colborder;
    int alienrow;
    int aliencol;
    int newrow;
    int newcol;
    char tileObject;
    char previousArrow;

    bool devmode = false;
    vector<vector<char>> map;

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
        int x;
        int y;
        int z;
        cout << "Change your game settings." << endl;
        cout << "---------------------------" << endl;
        bool choice = true;
        while (choice = true)
        {
            cout << "Tip : Row will be the size of the board from top to bottom." << endl;

            cout << "New Board Rows (1-11) : ";
            cin >> x;
            if (x % 2 == 1 && x < 12)
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
        while (choice2 = true)
        {
            cout << "Tip : Column will be the size of the board from left to right." << endl;
            cout << "New Board Columns (1-29): ";
            cin >> y;
            if (y % 2 == 1 && y < 30)
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
        // cout << "Zombie Count : "; cin >> z;
        Pause();
        ClearScreen();
    }

    void BoardSettings()
    {
        string a = "n";
        while (a == "n")
        {
            int defkRows = 5;
            int defkColumns = 15;
            cout << "Board Settings(Default)" << endl;
            cout << "---------------" << endl;
            cout << "Board Rows : " << defkRows << endl;
            cout << "Board Columns : " << defkColumns << endl;
            // cout << "Zombie Count : " <<(variable);

            cout << "Do you wish to change the game settings? (y/n/q to return) : ";
            string choice;
            cin >> choice;

            if (choice == "y")
            {
                ClearScreen();
                BoardEdit();
                break;
            }
            else if (choice == "n")
            {
                row = 5;
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
        HPlimit = 50;
        zRangeLimit = 4;
        zDmgLimit = 50;
        charge = 0;

        HP = 50 + (rand() % HPlimit);
        dmg = 0;

        zHP = 50 + (rand() % HPlimit);
        zDmg = 1 + (rand() % zDmgLimit);
        zRange = 1 + (rand() % 4);

        kRows = row;
        kColumns = col;
        rowborder = row - 1;
        colborder = col - 1;

        char objects[] = {'v', '^', '<', '>', ' ', 'h', 'p', 'r', ' ', ' ', ' ', 't'};
        int noOfObjects = 12; // number of objects in the array

        alienrow = (kRows / 2);
        aliencol = (kColumns / 2); // center of the map

        while (!(rowZom == alienrow && colZom == aliencol))
        {
            rowZom = rand() % ((kRows - 1) + 1);
            colZom = rand() % ((kColumns - 1) + 1);
            break;
        }

        map.resize(kRows); // create empty rows
        for (int i = 0; i < kRows; ++i)
        {
            map[i].resize(kColumns); // resize each row
        }

        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 0; col < kColumns; ++col)
            {
                if (row == alienrow && col == aliencol)
                {
                    map[row][col] = 'A'; // place alien
                }
                else if (row == rowZom && col == colZom)
                {
                    map[row][col] = 'Z'; // place zombie
                }
                else
                {
                    int objNo = rand() % noOfObjects;
                    map[row][col] = objects[objNo];
                }
            }
        }
    }
    
    void devCommands()
    {
        string command;
        bool commChoice = true;
        while (commChoice = true)
        {
            cout << "What are your commands, player?" << endl;
            cin >> command;
            if (command == "up")
            {
                moveUp();
                break;
            }
            if (command == "down")
            {
                moveDown();
                break;
            }
            if (command == "left")
            {
                moveLeft();
                break;
            }
            if (command == "right")
            {
                moveRight();
                break;
            }

            else if (command == "save")
            {
                gameSave();
                inProgressBoard();
                continue;
            }
            else if (command == "load")
            {
                gameLoad();
                system("cls");
                inProgressBoard();
                continue;
            }
            else if (command == "arrow")
            {
                arrowChange();
                arrowBoard();
                continue;
            }
            else if (command == "quit" || command == "q")
            {
                quit();
                break;
            }
            else if (command == "help")
            {
                helpMenu();
                break;
            }
            else if (command == "skip") // for testing purposes
            {
                // helpMenu();
                break;
            }
            else if (command == "shoot")
            {
                shoot();
                break;
            }
            else if (command == "teleport")
            {
                devTeleport();
                break;
            }
            else if (command == "cure") //kills all zombies
            {
                zHP = 0;
                break;
            }
            else if (command =="gg") //give up
            {
                HP = 0;
                break;
            }
            else if (command =="object")
            {
                objectChange();
                break;
            } 
            else
            {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
            break;
        }
        tileObject = ' ';
    }
    void commands()
    {
        string command;
        bool commChoice = true;
        while (commChoice = true)
        {
            cout << "What are your commands, player?" << endl;
            cin >> command;
            if (command == "up")
            {
                moveUp();
                break;
            }
            if (command == "down")
            {
                moveDown();
                break;
            }
            if (command == "left")
            {
                moveLeft();
                break;
            }
            if (command == "right")
            {
                moveRight();
                break;
            }

            else if (command == "save")
            {
                gameSave();
                inProgressBoard();
                continue;
            }
            else if (command == "load")
            {
                gameLoad();
                system("cls");
                inProgressBoard();
                continue;
            }
            else if (command == "arrow")
            {
                arrowChange();
                arrowBoard();
                continue;
            }
            else if (command == "quit" || command == "q")
            {
                quit();
                break;
            }
            else if (command == "help")
            {
                helpMenu();
                break;
            }
            else if (command == "devmode")
            {
                string password;
                cin >> password;
                if (password == "WongYaPingIsCool")
                {
                    devmode = true;
                    cout << "Developer cheats activated!" << endl;
                    HP = 9999;
                    charge = 999;
                }
                else
                {
                    cout << "Nice try..." << endl;
                }
                
                break;
            }
            else if (command == "shoot")
            {
                shoot();
                break;
            }
            else
            {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
            break;
        }
        tileObject = ' ';
    }

    void arrowChange()
    {
        int arRow;
        int arrowCol;
        cout << "Select which arrow you want to turn." << endl;
        cout << "Arrow Row: ";
        cin >> arRow;
        cout << "Arrow Column: ";
        cin >> arrowCol;
        bool arrowchoice = true;
        while (arrowchoice = true)
        {
            arRow = arRow - 1; // computers start with 0 instead of 1 so add 1 to match the board
            arrowCol = arrowCol - 1;
            row = arRow;
            col = arrowCol;
            if (map[row][col] == '>' || map[row][col] == '<' || map[row][col] == '^' || map[row][col] == 'v')
            {
                cout << "Choose a direction you want your arrow to face.(Up - U, Down - D , Left - L , Right - R)" << endl;
                cout << "Current arrow direction : " << map[row][col] << endl;
                char arrowD;
                cin >> arrowD;
                bool arrowC2 = true;
                while (arrowC2 = true)
                {
                    if (arrowD == 'U')
                    {
                        map[row][col] = '^';
                        cout << "Arrow direction has been changed!" << endl;
                        break;
                    }
                    else if (arrowD == 'D')
                    {
                        map[row][col] = 'v';
                        cout << "Arrow direction has been changed!" << endl;
                        break;
                    }
                    else if (arrowD == 'L')
                    {
                        map[row][col] = '<';
                        cout << "Arrow direction has been changed!" << endl;
                        break;
                    }
                    else if (arrowD == 'R')
                    {
                        map[row][col] = '>';
                        cout << "Arrow direction has been changed!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid direction. Try again." << endl;
                        continue;
                    }
                    break;
                }
            }
            else
            {
                cout << "The selected coordinate does not have an arrow in it." << endl;
            }
            break;
        }
    }

    void moveUp()
    {
        if (alienrow > 0)
        {
            tileObject = map[alienrow - 1][aliencol];
            if (tileObject == 'r')
            {
                rockSmash();
                map[alienrow - 1][aliencol] = tileObject;
                cout << "The alien smashes the rock!" << endl;
            }
            else if (tileObject == 'Z')
            {
                cout << "The alien does no damage to the zombie!" << endl;
            }

            else
            {
                map[alienrow - 1][aliencol] = 'A';
                map[alienrow][aliencol] = '.';
                alienrow = alienrow - 1;
                bool arrowmove = true;
                while (arrowmove = true)
                {
                    if (tileObject == '>' || tileObject == '^' || tileObject == 'v' || tileObject == '<')
                    {
                        objectContact();
                        arrowpush();
                        continue;
                    }
                    else
                    {
                        objectContact();
                        break;
                    }
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void moveDown()
    {
        if (alienrow < rowborder)
        {
            tileObject = map[alienrow + 1][aliencol];
            if (tileObject == 'r')
            {
                rockSmash();
                map[alienrow + 1][aliencol] = tileObject;
                cout << "The alien smashes the rock!" << endl;
            }
            else
            {
                tileObject = map[alienrow + 1][aliencol];
                map[alienrow + 1][aliencol] = 'A';
                map[alienrow][aliencol] = '.';
                alienrow = alienrow + 1;
                bool arrowmove = true;
                while (arrowmove = true)
                {
                    if (tileObject == '>' || tileObject == '^' || tileObject == 'v' || tileObject == '<')
                    {
                        objectContact();
                        arrowpush();
                        continue;
                    }
                    else if (tileObject == 'r')
                    {
                        rockSmash();
                        if (previousArrow == '>')
                        {
                            map[alienrow][aliencol + 1] = tileObject;
                            cout << "The alien smashes the rock!" << endl;
                        }
                        else if (previousArrow == '<')
                        {
                            map[alienrow][aliencol - 1] = tileObject;
                            cout << "The alien smashes the rock!" << endl;
                        }
                        else if (previousArrow == '^')
                        {
                            map[alienrow - 1][aliencol] = tileObject;
                            cout << "The alien smashes the rock!" << endl;
                        }
                        else if (previousArrow == 'v')
                        {
                            map[alienrow + 1][aliencol] = tileObject;
                            cout << "The alien smashes the rock!" << endl;
                        }
                    }

                    else
                    {
                        objectContact();
                        break;
                    }
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void moveLeft()
    {

        if (aliencol > 0)
        {
            tileObject = map[alienrow][aliencol - 1];
            if (tileObject == 'r')
            {
                rockSmash();
                map[alienrow][aliencol - 1] = tileObject;
                cout << "The alien smashes the rock!" << endl;
            }
            else
            {
                tileObject = map[alienrow][aliencol - 1];
                map[alienrow][aliencol - 1] = 'A';
                map[alienrow][aliencol] = '.';
                aliencol = aliencol - 1;
                bool arrowmove = true;
                while (arrowmove = true)
                {

                    if (tileObject == '>' || tileObject == '^' || tileObject == 'v' || tileObject == '<')
                    {
                        objectContact();
                        arrowpush();
                        continue;
                    }
                    else
                    {
                        objectContact();
                        break;
                    }
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void moveRight()
    {
        if (aliencol < colborder)
        {
            tileObject = map[alienrow][aliencol + 1];
            if (tileObject == 'r')
            {
                rockSmash();
                map[alienrow][aliencol + 1] = tileObject;
                cout << "The alien smashes the rock!" << endl;
            }
            else
            {
                tileObject = map[alienrow][aliencol + 1];
                map[alienrow][aliencol + 1] = 'A';
                map[alienrow][aliencol] = '.';
                aliencol = aliencol + 1;
                bool arrowmove = true;
                while (arrowmove = true)
                {
                    if (tileObject == '>' || tileObject == '^' || tileObject == 'v' || tileObject == '<')
                    {
                        objectContact();
                        arrowpush();
                        continue;
                    }
                    else
                    {
                        objectContact();
                        break;
                    }
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void rockSmash()
    {
        char rockObject[] = {' ', '^', 'v', '>', '<', 'h', 'p', 't'};
        int noObjects = 8;
        int newRock = rand() % noObjects;
        tileObject = rockObject[newRock];
    }

    void gameSave()
    {
        ofstream savefile;
        string filename;

        cout << "Enter the name of the new save file : ";
        cin >> filename;
        savefile.open(filename); // opens the file

        
        ofstream out_file(filename);

        for (int row = 0; row < kRows; row++)
        {
            for (int col = 0; col < kColumns; col++)
            {
                savefile << map[row][col];
            }
        }
        savefile << endl;

        savefile << HP << endl;
        savefile << charge <<endl;
        savefile << zHP << endl;
        savefile << zDmg << endl;
        savefile << zRange << endl;
        savefile << aliencol << endl;
        savefile << alienrow << endl;
        savefile << rowZom << endl;
        savefile << colZom << endl;
        savefile << kRows << endl;
        savefile << kColumns << endl;
        savefile << endl;
        savefile.close();

        bool choice = true;
        while (choice = true)
        {
            string input;
            cout << "Do you want to quit or continue the game? (q/c) : ";
            cin >> input;

            if (input == "q")
            {
                quit();
                break;
            }
            else if (input == "c")
            {
                break;
            }
            else
            {
                cout << "Invalid input, please try again." << endl;
            }
            break;
        }
    }

    void gameLoad()
    {
        system("cls");
        ifstream loadfile, binary;
        string mapstring, filename;
        vector<int> values;
        int number;
        char letter;
        int count = 0;
        bool choice = true;
        while (choice = true)
        {
            cout << "Enter the name of the save file of your choice : "; // User input for the file name of the txt file
            cin >> filename;
            loadfile.open(filename); // opens the file with the name inputted by user
            if (loadfile.is_open())  // checks if the file requested by user is open
            {
                while (getline(loadfile, mapstring)) // gather all string in txt file
                {
                    if (loadfile >> letter) // check if it is a char
                    {
                        int mapchar = 0;
                        for (int row = 0; row < kRows; row++)
                        {
                            for (int col = 0; col < kColumns; col++)
                            {
                                map[row][col] = mapstring[mapchar];
                                mapchar = mapchar + 1;
                            }
                        }
                    }
                };
                break;
                while (loadfile >> number)
                {
                    values.push_back(number);
                };
                break;
                loadfile.close(); // close file (to basically save all changes made)
                break;
            }
            else
            {
                cout << "File doesn't exist, please try again." << endl;
                continue;
            }
        }
        Pause();
    }

    void quit()
    {
        string x;
        cout << "Are you sure you want to quit the game? (y/n) : ";
        cin >> x;
        bool Qchoice = true;
        while (Qchoice = true)
        {

            if (x == "y")
            {
                cout << "Thanks for playing!" << endl;
                Pause();
                exit(0);
                break;
            }
            else if (x == "n")
            {
                cout << "The game will continue. Good luck!" << endl;
                break;
            }
            else
            {
                cout << "Invalid input, please try again.";
                continue;
            }
            break;
        }
    }

    void helpMenu()
    {
        ClearScreen();
        string x;

        cout << "  _________________________________________________________________" << endl;
        cout << " |  Command |                     Description                      | " << endl;
        cout << " |__________|______________________________________________________| " << endl;
        cout << " |    up    | Move alien upwards                                   |" << endl;
        cout << " |   down   | Move alien downwards                                 |" << endl;
        cout << " |   left   | Move alien to the left                               |" << endl;
        cout << " |   right  | Move alien to the right                              |" << endl;
        cout << " |   shoot  | Expend 3 charges and shoot the zombie for 15HP when  |" << endl;
        cout << " |          | it is within 5 blocks away from the alien            |" << endl;
        cout << " |   arrow  | Switch the direction of an arrow object in the board |" << endl;
        cout << " |   save   | Save the current game                                |" << endl;
        cout << " |   load   | Load a saved game                                    |" << endl;
        cout << " |   quit   | Quit the game                                        |" << endl;
        cout << " |__________|______________________________________________________|" << endl;
        cout << "                                                                     " << endl;
    }

    void objectContact()
    {
        if (tileObject == 'h')
        {
            HP = HP + 20;
        }
        else if (tileObject == '<' || tileObject == '>' || tileObject == '^' || tileObject == 'v')
        {
            dmg = dmg + 20;
        }
        else if (tileObject == 'p')
        {
            if (zHP > 10)
            {
                zHP = zHP - 10;
            }
            else
            {
                zHP = 0;
            }
        }
        else if (tileObject == 'r')
        {
            rockSmash();
            if (previousArrow == '^')
            {
                map[alienrow - 1][aliencol] = tileObject;
            }
            else if (previousArrow == 'v')
            {
                map[alienrow + 1][aliencol] = tileObject;
            }
            else if (previousArrow == '>')
            {
                map[alienrow][aliencol + 1] = tileObject;
            }
            else if (previousArrow == '^')
            {
                map[alienrow][aliencol - 1] = tileObject;
            }
            cout << "The alien smashes the rock!" << endl;
        }
        else if (tileObject == 'Z')
        {
            cout << "The alien attacks the zombie after a hard charge!" << endl;
        }
        else if (tileObject == 't')
        {
            char randomisedObjects[] = {'v', '^', '<', '>', ' ', 'h', 'p', 'r', ' ', ' ', ' '};
            int teleportObject = 10;
            int newteleportObject = rand() % teleportObject;

            int teleportRow = rand() % kRows - 1; // picks a random location
            int teleportCol = rand() % kColumns - 1;
            map[teleportRow][teleportCol] = 'A';                            // sets the new random coordinates as the alien
            map[alienrow][aliencol] = randomisedObjects[newteleportObject]; // places a new randomised object on the teleporter
            alienrow = teleportRow;                                         // sets new alien coordinates
            aliencol = teleportCol;

            cout << "The alien has been teleported to a random location on the map!" << endl;
        }

        else
        {
            // literally nothing happens!!!
        }
    }

    void arrowpush()
    {
        if (tileObject == '<')
        {
            if (aliencol > 0)
            {
                if (map[alienrow][aliencol - 1] == 'r')
                {
                    tileObject = map[alienrow][aliencol - 1];
                    previousArrow = '<';
                }
                else if (map[alienrow][aliencol - 1] == 'Z')
                {
                    tileObject = map[alienrow][aliencol - 1];
                    zHP = zHP - dmg;
                }
                else
                {
                    previousArrow = '<';
                    tileObject = map[alienrow][aliencol - 1];
                    map[alienrow][aliencol - 1] = 'A';
                    map[alienrow][aliencol] = '.';
                    aliencol = aliencol - 1;
                }
            }
            else
            {
                tileObject = map[alienrow][aliencol - 1];
            }
        }
        else if (tileObject == '>')
        {
            if (aliencol < colborder - 1)
            {
                if (map[alienrow][aliencol + 1] == 'r')
                {
                    tileObject = map[alienrow][aliencol + 1];
                    previousArrow = '>';
                }
                else if (map[alienrow][aliencol + 1] == 'Z')
                {
                    tileObject = map[alienrow][aliencol + 1];
                    zHP = zHP - dmg;
                }
                else
                {
                    previousArrow = '>';
                    tileObject = map[alienrow][aliencol + 1];
                    map[alienrow][aliencol + 1] = 'A';
                    map[alienrow][aliencol] = '.';
                    aliencol = aliencol + 1;
                }
            }
            else
            {
                tileObject = map[alienrow][aliencol + 1];
            }
        }
        else if (tileObject == '^')
        {
            if (alienrow > 0)
            {
                if (map[alienrow - 1][aliencol] == 'r')
                {
                    tileObject = map[alienrow - 1][aliencol];
                    previousArrow = '^';
                }
                else if (map[alienrow - 1][aliencol] == 'Z')
                {
                    tileObject = map[alienrow - 1][aliencol];
                    zHP = zHP - dmg;
                }
                else
                {
                    previousArrow = '^';
                    tileObject = map[alienrow - 1][aliencol];
                    map[alienrow - 1][aliencol] = 'A';
                    map[alienrow][aliencol] = '.';
                    alienrow = alienrow - 1;
                }
            }
            else
            {
                tileObject = ' ';
            }
        }
        else if (tileObject == 'v')
        {
            if (alienrow < rowborder - 1)
            {
                if (map[alienrow + 1][aliencol] == 'r')
                {
                    tileObject = map[alienrow + 1][aliencol];
                    previousArrow = 'v';
                }
                else if (map[alienrow + 1][aliencol] == 'Z')
                {
                    tileObject = map[alienrow + 1][aliencol];
                    zHP = zHP - dmg;
                }
                else
                {
                    previousArrow = 'v';
                    tileObject = map[alienrow + 1][aliencol];
                    map[alienrow + 1][aliencol] = 'A';
                    map[alienrow][aliencol] = '.';
                    alienrow = alienrow + 1;
                }
            }
            else
            {
                tileObject = ' ';
            }
        }
    }

    void trailReset()
    {
        char newObjects[] = {'>', '<', '^', 'v', ' ', 'h', 'r', 'p'};
        int numberObject = 8;
        for (int row = 0; row < kRows; row++) // searches for any dots inside the map to replace
        {
            for (int col = 0; col < kColumns; col++)
            {
                if (map[row][col] == '.')
                {
                    int objNum = rand() % numberObject;
                    map[row][col] = newObjects[objNum];
                }
            }
        }
    }

    void ShowGameBoard()
    {
        ClearScreen();
        cout << "  _______________________________" << endl;
        cout << " | Player, be ready for battle!  |" << endl;
        cout << " |_______________________________|" << endl;
        cout << "                                  " << endl;
        for (int row = 0; row < kRows; ++row)
        {
            cout << "  +---";
            for (int col = 0; col < kColumns - 1; ++col)
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            // display row number
            cout << setw(2) << row + 1;

            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << map[row][col] << " "; // shows the stuff inside the map
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

        // display column number
        cout << "   ";
        for (int j = 0; j < col; ++j)
        {
            int digit = (j + 1) / 10; // for > 10 numbers
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
            cout << "  ";
        }

        cout << endl;
        cout << " ";
        for (int j = 0; j < col; ++j)
        {
            cout << "   " << (j + 1) % 10;
        }

        cout << endl;
        cout << "Row : Top to down." << endl;
        cout << "Column : Left to right." << endl;
        cout << endl
             << endl;
        Alien stats;
        stats.lifeSet(HP);
        stats.showLife();
        cout << "        ";
        stats.attackSet(dmg);
        stats.showdamage();
        cout << "        ";
        stats.chargeSet(charge);
        stats.showCharge();
        cout << endl;

        Zombie Zstats;
        Zstats.ZlifeSet(zHP);
        Zstats.showZLife();
        cout << "        ";
        Zstats.ZattackSet(zDmg);
        Zstats.showZDamage();
        Zstats.zombieRange(zRange);
        cout << "        ";
        Zstats.showRange();
        cout << endl
             << endl;
        commands();
    }

    void inProgressBoard()
    {
        system("cls");
        cout << "  ________________________________________________" << endl;
        cout << " | The battle has begun! Who will be victorious?  |" << endl;
        cout << " |________________________________________________|" << endl;
        cout << "                                  " << endl;
        for (int row = 0; row < kRows; ++row)
        {
            cout << "  +---";
            for (int col = 0; col < kColumns - 1; ++col)
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            cout << setw(2) << row + 1;
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << map[row][col] << " "; // shows the stuff inside the map
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

        // display column number
        cout << "   ";
        for (int j = 0; j < kColumns; ++j)
        {
            int digit = (j + 1) / 10; // for > 10 numbers
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
            cout << "  ";
        }

        cout << endl;
        cout << " ";
        for (int j = 0; j < kColumns; ++j)
        {
            cout << "   " << (j + 1) % 10;
        }
        cout << endl;
        cout << "Row : Top to down." << endl;
        cout << "Column : Left to right." << endl;
        cout << endl;

        if (charge < 3)
        {
            charge = charge + 1;
        }

        Alien stats;
        stats.lifeSet(HP);
        stats.showLife();
        cout << "        ";
        stats.attackSet(0);
        stats.showdamage();
        cout << "        ";
        stats.chargeSet(charge);
        stats.showCharge();
        cout << endl;

        Zombie Zstats;
        Zstats.ZlifeSet(zHP);
        Zstats.showZLife();
        cout << "        ";
        Zstats.ZattackSet(zDmg);
        Zstats.showZDamage();
        Zstats.zombieRange(zRange); // range
        cout << "        ";
        Zstats.showRange();
        cout << endl
             << endl;
        if (devmode == true)
        {
            cout << "(Dev mode active)" <<endl;
            devCommands();
        }
        else
        {
            commands();
        }  
    }

    void arrowBoard()
    {
        system("cls");
        cout << "  ________________________________________________" << endl;
        cout << " |        The alien prepares its next move!       |" << endl;
        cout << " |________________________________________________|" << endl;
        cout << "                                  " << endl;
        for (int row = 0; row < kRows; ++row)
        {
            cout << "  +---";
            for (int col = 0; col < kColumns - 1; ++col)
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            cout << setw(2) << row + 1;
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << map[row][col] << " "; // shows the stuff inside the map
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

        // display column number
        cout << "   ";
        for (int j = 0; j < kColumns; ++j)
        {
            int digit = (j + 1) / 10; // for > 10 numbers
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
            cout << "  ";
        }

        cout << endl;
        cout << " ";
        for (int j = 0; j < kColumns; ++j)
        {
            cout << "   " << (j + 1) % 10;
        }
        cout << endl;
        cout << "Row : Top to down." << endl;
        cout << "Column : Left to right." << endl;
        cout << endl;

        Alien stats;
        stats.lifeSet(HP);
        stats.showLife();
        cout << "        ";
        stats.attackSet(0);
        stats.showdamage();
        cout << "        ";
        stats.chargeSet(charge);
        stats.showCharge();
        cout << endl;

        Zombie Zstats;
        Zstats.ZlifeSet(zHP);
        Zstats.showZLife();
        cout << "        ";
        Zstats.ZattackSet(zDmg);
        Zstats.showZDamage();
        Zstats.zombieRange(zRange); // range
        cout << "        ";
        Zstats.showRange();
        cout << endl
             << endl;
    }

    void zombieBoard()
    {
        for (int row = 0; row < kRows; ++row)
        {
            cout << "  +---";
            for (int col = 0; col < kColumns - 1; ++col)
            {
                cout << "+---";
            }
            cout << "+";
            cout << endl;
            cout << setw(2) << row + 1;
            for (int col = 0; col < kColumns; ++col)
            {
                cout << "| ";
                cout << map[row][col] << " "; // shows the stuff inside the map
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

        // display column number
        cout << "   ";
        for (int j = 0; j < kColumns; ++j)
        {
            int digit = (j + 1) / 10; // for > 10 numbers
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
            cout << "  ";
        }

        cout << endl;
        cout << " ";
        for (int j = 0; j < kColumns; ++j)
        {
            cout << "   " << (j + 1) % 10;
        }
        cout << endl;
        cout << "Row : Top to down." << endl;
        cout << "Column : Left to right." << endl;
        cout << endl;
    }

    void zombieTurn()
    {
        system("cls");
        cout << "  ________________________________________________" << endl;
        cout << " |        The zombie has taken its turn!          |" << endl;
        cout << " |________________________________________________|" << endl;
        cout << endl;
        char zrand[] = {'v', '^', '<', '>'}; // determine the zombie's move
        int zombierandom = 4;
        char zTurn = rand() % zombierandom;
        char zAction = zrand[zTurn];
        if (zAction == 'v')
        {
            if (rowZom < rowborder)
            {
                if (map[rowZom + 1][colZom] == 'A') // checks if the direction would result in it moving directly into the alien
                {
                    zombieBoard();
                    cout << "The zombie gives the alien a cold, hard stare, ready for an attack." << endl;
                    Pause();
                }
                else
                {
                    map[rowZom + 1][colZom] = 'Z';
                    map[rowZom][colZom] = ' ';
                    rowZom = rowZom + 1;
                    zombieBoard();
                    cout << endl;
                    cout << "The zombie has moved downwards!" << endl;
                }
            }
            else
            {
                zombieBoard();
                cout << endl;
                cout << "The zombie tried to move, but it ran into a wall.(Downwards)" << endl;
            }
        }
        else if (zAction == '^')
        {
            if (rowZom > 0)
            {
                if (map[rowZom - 1][colZom] == 'A') // checks if the direction would result in it moving directly into the alien
                {
                    zombieBoard();
                    cout << "The zombie gives the alien a cold, hard stare, ready for an attack." << endl;
                    Pause();
                }
                else
                {
                    map[rowZom - 1][colZom] = 'Z';
                    map[rowZom][colZom] = ' ';
                    rowZom = rowZom - 1;
                    zombieBoard();
                    cout << endl;
                    cout << "The zombie has moved upwards!" << endl;
                }
            }
            else
            {
                zombieBoard();
                cout << endl;
                cout << "The zombie tried to move, but it ran into a wall.(Upwards)" << endl;
            }
        }
        else if (zAction == '>')
        {
            if (colZom < colborder)
            {
                if (map[rowZom][colZom + 1] == 'A') // checks if the direction would result in it moving directly into the alien
                {
                    zombieBoard();
                    cout << "The zombie gives the alien a cold, hard stare, ready for an attack." << endl;
                    Pause();
                }
                else
                {
                    map[rowZom][colZom + 1] = 'Z';
                    map[rowZom][colZom] = ' ';
                    colZom = colZom + 1;
                    zombieBoard();
                    cout << endl;
                    cout << "The zombie has moved to the right!" << endl;
                }
            }
            else
            {
                zombieBoard();
                cout << endl;
                cout << "The zombie tried to move, but it ran into a wall.(To the right)" << endl;
            }
        }
        else if (zAction == '<')
        {

            if (colZom > 0)
            {
                if (map[rowZom][colZom - 1] == 'A') // checks if the direction would result in it moving directly into the alien
                {
                    zombieBoard();
                    cout << "The zombie gives the alien a cold, hard stare, ready for an attack." << endl;
                    Pause();
                }
                else
                {
                    map[rowZom][colZom - 1] = 'Z';
                    map[rowZom][colZom] = ' ';
                    colZom = colZom - 1;
                    zombieBoard();
                    cout << endl;
                    cout << "The zombie has moved to the left!" << endl;
                }
            }
            else
            {
                zombieBoard();
                cout << endl;
                cout << "The zombie tried to move, but it ran into a wall.(To the left)" << endl;
            }
        }
    }
    void gameOver()
    {
        cout << " The zombie has taken down the alien!!" << endl;
        cout << "           You are defeated!          " << endl;
        cout <<"                _____"<< endl;
        cout <<"              |       |"<< endl;
        cout <<"             |         | "<< endl;
        cout <<"             |  () ()  |"<< endl;
        cout <<"              |       |"<< endl;
        cout <<"               |  ^  |"<< endl;
        cout <<"                |||||"<< endl;
    }
    void victory()
    {
        system("cls");
        cout << "The zombie has been defeated by the alien!" << endl;
        cout << "           You are victorious!            " << endl;
        cout << "           Here is your prize.            " << endl;
        cout << "           '._==_==_=_.'" << endl;
        cout << "           .-|:      |-." << endl;
        cout << "          | (|:.     |) |" << endl;
        cout << "           '-|:.     |-'" << endl;
        cout << "             |::.    |" << endl;
        cout << "             '::. .' " << endl;
        cout << "                ) (" << endl;
        cout << "              _.' '._" << endl;
        cout << "            "
                ""
                ""
                ""
                ""
                ""
             << endl;
    }

    void activeBoard()
    {
        bool gaming = true;
        while (gaming = true)
        {
            if (HP > 0 && zHP > 0)
            {
                inProgressBoard();
                Pause();
                if (zHP > 0)
                {
                    zombieTurn();
                    zombieAttack();
                    Pause();
                    trailReset();
                    continue;
                }
                else
                {
                    victory();
                    break;
                }   
            }
            else if (HP < 1)
            {
                system("cls");
                gameOver();
                break;
            }
            else if (zHP < 1)
            {
                system("cls");
                victory();
                break;
            }
            break;
        }
    }

    void zombieAttack()
    {
        int colrange = colZom - aliencol;
        int rowrange = rowZom - alienrow;
        if (colrange < 0)
        {
            colrange = -colrange;
        }
        if (rowrange < 0)
        {
            rowrange = -rowrange;
        }

        if (colrange <= zRange && rowrange <= zRange)
        {
            HP = HP - zDmg;
            cout << "The zombie attacks the alien for " << zDmg << " Damage!" << endl;
        }
        else
        {
            cout << "The zombie tries to attack the alien, but it is out of range." << endl;
        }
    }

    void shoot()
    {
        int CharCol = colZom - aliencol;
        int CharRow = rowZom - alienrow;

        bool shoot = true;
        while (shoot = true)
        {

            if (charge = 3 && (CharCol && CharRow <= 5))
            {

                zHP = zHP - 15;
                cout << "The alien shoots and hit the zombie!" << endl;
                charge = -1;
                break;
            }
            else if (charge < 3)
            {
                cout << "Not enough charges to shoot!" << endl;
                Pause();
                break;
            }
            else if (CharCol && CharRow <= 5)
            {
                cout << "The alien tries to shoot the zombie but the zombie is not in range!" << endl;
                charge = 0;
                Pause();
                break;
            }
        }
    }
    
    void devTeleport()
    {
        cout << "Choose a teleport destination." << endl;
        cout << "Row: " << endl;
        cin >> newrow;
        cout << "Column: " << endl;
        cin >> newcol;
        newrow = newrow - 1; //take into account computers starting at 0 instead of 1
        newcol = newcol - 1;
        if (map[newrow][newcol] == 'Z')
        {
            cout << "Invalid teleport." << endl;
        }
        else
        {
            map[newrow][newcol] = 'A';
            map[alienrow][aliencol] = ' ';
            alienrow = newrow;
            aliencol = newcol;
        } 
    }

    void objectChange()
    {
        int objRow;
        int objCol;
        bool validPlace = true;
        while(validPlace = true)
        {
        cout << "Choose the location of the object." << endl;
        cout << "Row: " << endl;
        cin >> objRow;
        objRow = objRow - 1;
        cout << "Column: " << endl;
        cin >> objCol;
        objCol = objCol - 1;
        if (map[objRow][objCol] == 'Z')
        {
            cout << "Invalid location. The zombie is in that place. Try again." << endl;
            continue;
        }
        else
        {
        bool validObj = true;
        while(validObj = true)
        {
        cout << "Choose an item to place." << endl;
        char newObj;
        cout << "<  v  >  ^  r  h  p" << endl;
        cin >> newObj;
        switch (newObj)
        {
        case '<':
            map[objRow][objCol] = '<';
            cout << "Object updated!" << endl;
            break;
        case '>':
            map[objRow][objCol] = '>';
            cout << "Object updated!" << endl;
            break;
        case '^':
            map[objRow][objCol] = '^';
            cout << "Object updated!" << endl;
            break;
        case 'v':
            map[objRow][objCol] = 'v';
            cout << "Object updated!" << endl;
            break;
        case 'r':
            map[objRow][objCol] = 'r';
            cout << "Object updated!" << endl;
            break;
        case 'h':
            map[objRow][objCol] = 'h';
            cout << "Object updated!" << endl;
            break;
        case 'p':
            map[objRow][objCol] = 'p';
            cout << "Object updated!" << endl;
            break;
        
        default:
            cout << "Invalid object. Try again." << endl;
            break;
        }
        break;
        }
        }
        break;
        }
    }
}

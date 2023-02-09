#include "helper.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <numeric>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include "alien.cpp"
using namespace std;
namespace pf
{

    int kRows;
    int kColumns;
    int rowZom;
    int colZom;
    int HP;
    int dmg;

    int row; // up down size
    int col; // left right size
    int alienrow;
    int aliencol;
    int newrow;
    int newcol;
    char tileObject;
    vector<vector<char>> map;
    vector<vector<char>> savemap;

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
        // kufufu kufufu kufufu
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
        HP = 100;
        dmg = 0;
        kRows = row;
        kColumns = col;

        char objects[] = {'v', '^', '<', '>', ' ', 'h', 'p', 'r', ' ', ' ', ' '};
        int noOfObjects = 11; // number of objects in the array

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
                    map[row][col] = 'A';
                }
                else if (row == rowZom && col == colZom)
                {
                    map[row][col] = 'Z';
                }
                else
                {
                    int objNo = rand() % noOfObjects;
                    map[row][col] = objects[objNo];
                }
            }
        }
    }

    void commands()
    {
        string command;
        cout << "What are your commands, player?" << endl;
        bool commChoice = true;
        while (commChoice = true)
        {
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
                break;
            }
            else if (command == "load")
            {
                gameLoad();
                break;
            }
            else if (command == "arrow")
            {
                arrowChange();
                break;
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
            else
            {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
            break;
        }
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
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void moveDown()
    {
        if (alienrow <= kRows)
        {
            tileObject = map[alienrow + 1][aliencol];
            map[alienrow + 1][aliencol] = 'A';
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
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void moveRight()
    {
        if (aliencol <= kColumns)
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
        else
        {
            cout << "Invalid move." << endl;
        }
    }

    void gameSave()
    {
        ofstream savefile;
        string filename;

        cout << "Enter the name of the new save file : ";
        cin >> filename;
        savefile.open(filename);

        // Saving the "CHANGE THIS TO THE GAME BOARD" string into the txt file
        for (int i = 0; i < map.size(); i++)
        {
            // savefile << map[i]<<endl;
        }
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
                // backtogame(IDK THE FUNC)
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
        ifstream loadfile;
        string map, filename;

        bool choice = true;
        while (choice = true)
        {
            cout << "Enter the name of the save file of your choice : "; // User input for the file name of the txt file
            cin >> filename;
            loadfile.open(filename); // opens the file with the name inputted by user
            if (loadfile.is_open())  // checks if the file requested by user is open
            {
                while (getline(loadfile, map)) // gather all string in txt file
                {
                    cout << map << endl; // print the strings in the txt file
                };
                loadfile.close(); // close file (to basically save all changes made)
                break;
            }
            else
            {
                cout << "File doesn't exist, please try again." << endl;
            }
        }
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
            // insert zombie code here(real)(not fake)
        }
        else if (tileObject == 'r')
        {
            // Bocchi the rock
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
                tileObject = map[alienrow][aliencol - 1];
                map[alienrow][aliencol - 1] = 'A';
                map[alienrow][aliencol] = '.';
                aliencol = aliencol - 1;
            }
        }
        else if (tileObject == '>')
        {
            tileObject = map[alienrow][aliencol + 1];
            map[alienrow][aliencol + 1] = 'A';
            map[alienrow][aliencol] = '.';
            aliencol = aliencol + 1;
        }
        else if (tileObject == '^')
        {
            if (alienrow > 0)
            {
                tileObject = map[alienrow - 1][aliencol];
                map[alienrow - 1][aliencol] = 'A';
                map[alienrow][aliencol] = '.';
                alienrow = alienrow - 1;
            }
        }
        else if (tileObject == 'v')
        {
            tileObject = map[alienrow + 1][aliencol];
            map[alienrow + 1][aliencol] = 'A';
            map[alienrow][aliencol] = '.';
            alienrow = alienrow - 1;
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
        cout << endl
             << endl;
        ;
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
        Alien stats;
        stats.lifeSet(HP);
        stats.showLife();
        cout << "        ";
        stats.attackSet(dmg);
        stats.showdamage();
        cout << endl
             << endl;
        commands();
    }
}

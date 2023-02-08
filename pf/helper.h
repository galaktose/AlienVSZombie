#ifndef PF_HELPER_H
#define PF_HELPER_H
namespace pf
{
    int ClearScreen();
    int Pause();
    
    void BoardSettings();
    void BoardEdit();
    void CreateGameBoard();
    void ShowGameBoard();
    void inProgressBoard();
    void commands();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void arrowChange();
    void gameSave();
    void gameLoad();
    void quit();
    void helpMenu();
    void objectContact();
}


#endif
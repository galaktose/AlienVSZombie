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
    void arrowBoard();
    void commands();
    void trailReset();
    void activeBoard();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void arrowChange();
    void rockSmash();

    void gameSave();
    void gameLoad();
    void continueGame();
    void gameOver();
    void victory();
    
    void quit();
    void helpMenu();
    void objectContact();
    void arrowpush();

    void zombieBoard();
    void zombieTurn();
}


#endif
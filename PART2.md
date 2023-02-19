# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Game controls 
2. Random map and game object generation
3. Customisable board size
4. Alien movement(including arrows)
5. Zombie movement(randomised)
6. Zombie range
7. Option to play again after win/loss
8. Pod
9. Health packs
10. Rock smash(including arrows)
11. Revealing the game object after a rock is smashed

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Multiple zombies
2. Loading the game

## Additional Features

1. Teleporter game object
    - A new game object that teleports the alien to a random place inside the board. After teleporting, the teleporter will be randomised into a new game object that is not another teleporter.

2. Alien "shoot" command
    - The alien is given the ability to attack a  zombie from a very large distance, nearly infinite for smaller boards such as the default board(A range of 5). This ability can only be used once the alien accumulates a charge of 3, which is reset after the alien uses the shoot command. This attack ends the alien's turn, and does only 15 damage to the zombie.
3. Developer Mode
    - The user can type in "devmode" as one of the possible commands. This command will not be listed in the help menu, and once its typed in, it will go to a new line below but seemingly not ask the user for an input. If the correct password is entered, the player will enter devmode.

    In dev mode,
    -The player will be given 9999 health and 999 charge.
    -The player will get 4 new commands. The first one, teleport, allows the player to teleport anywhere on the map according to their inputs. The second and third, "cure" and "gg" allow the player to instantly eliminate the zombie or alien respectively, and instantly see the game over or victory screen. The last one, "object" allows the player to place a game object in a desired location. The player cannot teleport onto or change the object of the zombie.

    -Once the game ends, dev mode is disabled.

## Contributions

### Noor Hannan bin Noor Hamsuruddin

1. Map generation
2. Game Controls
3. Board size customisation
4. Alien attacks
5. Zombie randomised movement
6. Zombie attacks
7. Interaction with game objects
8. Developer mode(all features)
9. Teleporter
10. Finished game save

### Wan Muhammad Atif bin Taram Satiraksa

1. Frameworks for Game Saving and Loading
2. Alien "shoot" feature 
3. Randomisation of Zombie, Alien stats
4. Help menu
5. Zombie.cpp
6. Partial assistance on other features (Map generation, Board size customisation and Zombie attacks)

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
1. Randomising the initial values of the game character's HP, ATK and Range (for Zombies) within a set range
    - figured out the formula being ;
    ``` 
    int random = offset + (rand() % range); 
    ```
      where offset is the starting limit and range is the number of values between first and last limit including the limits itself.

2. Zombie having infinite range.
    - Found a logic error where zombie can attack if the alien is only a few rows away OR a few columns away. Fixed by using the AND operator.

3. Arrows allow the alien to go off the board and possibly end the code forcefully.
    -Modified some logical errors and added more restrictions to ensure the alien does not go off the board after going through arrows.

4. Alien overlaps the rock after smashing it  
    - Modified arrowpush() to take into account stopping at a rock and smashing it  
 
5. Save and load feature does not work.
    - gg
# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Game controls (except for save and load)
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

## Contributions

### Noor Hannan bin Noor Hamsuruddin

1. Map generation
2. Game Controls
3. Board size customisation
4. Alien attacks
5. Zombie randomised movement
6. Zombie attacks
7. Interaction with game objects

### Wan Muhammad Atif bin Taram Satiraksa

1. Go on add your contributions


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
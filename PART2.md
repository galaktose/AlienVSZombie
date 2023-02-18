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
2. Saving and loading the game

## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.

For example:

### Tony Stark

1. Randomly generate game board.
2. *add more*

### Steve Rogers

1. Zombie movement and attack behaviour.
2. *add more*


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
    -(pain)

4. Alien overlaps the rock after smashing it
    - Modified arrowpush() to take into account stopping at a rock and smashing it 
# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Cool Feature #1
2. Cool Feature #2
3. *add more*

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Cool Feature #1
2. *add more*

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

### Dr. Strange

1. Implement all game objects.
2. *add more*

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
1. Randomising the initial values of the game character's HP, ATK and Range (for Zombies) within a set range
    - figured out the formula being ;
    ``` 
    int random = offset + (rand() % range); 
    ```
      where offset is the starting limit and range is the number of values between first and last limit including the limits itself.
2. Zombie having infinite range
    - (to be updated)
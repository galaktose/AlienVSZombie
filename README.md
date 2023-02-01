# Alien vs. Zombie

Aliens vs. Zombie is a text-based game inspired by the hit mobile game "Alien Path". In this game, you play as an Alien on a path to exterminate zombies. This game combines several game elements such as RPG and Strategy to produce an exhilarating and one of a kind gameplay. 

![Alt text](pf/gameplay.jfif "Gameplay!")

Please provide the YouTube link to your [Video Demo](https://youtu.be/dMx48-AR7vM).

## Compilation Instructions

```
Open cmd (when in the AlienVSZombie folder and type in :

g++ main.cpp pf/helper.cpp  

An executable "main.exe" will be available in the AlienVSZombie directory. Run it.
```

## User Manual

To run : Execute by clicking on main.exe via File Explorer 
Alternatively, use cmd, cd to the directory containing main.exe and type ;

start main.exe

Players can edit and change their board sizes before the game starts. 
The default rows and columns value are 5 and 15 respectively. 

[Game Objects]
Arrow 
^ (up),
v (down),
< (left),
> (right)

• Changes Alien’s direction of movement.
• Adds 20 attack to Alien.

Health  (h) 
• Adds 20 life to Alien.

Pod (p) 
• Instantly inflicts 10 damage to Zombie when hit by Alien.

Rock (r) 
• Hides a game object (except Rock and Trail) beneath it.
• Reveals the hidden game object when hit by Alien.
• Stops the Alien from moving.

Empty Space 
• Just an empty space on the board.

Trail (.) 
• Left by Alien when it moves.
• Reset to a random game object (except the Trail) after Alien’s turn ends.

For further gameplay questions, A help menu can be accessed in game by typing "help".


## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- Noor Hannan bin Noor Hamsuruddin
- Wan Muhammad Atif bin Taram Satiraksa



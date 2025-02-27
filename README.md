So Long - 2D Game

Project Overview
"So Long" is a simple 2D game where the player’s goal is to collect all the collectibles on a map and then find the shortest escape route. The game is built using C programming and the MiniLibX graphics library. It challenges you to work with textures, sprites, and basic gameplay mechanics such as window management, event handling, and user input.

Features
Movement: The player can move up, down, left, or right using the W, A, S, and D keys (or ZQSD/arrow keys).
Map: The map is represented using a simple grid where:
0 represents empty space
1 represents walls
C represents collectibles
E represents the exit
P represents the player’s starting position
Objective: The player must collect all collectibles and then escape through the exit.
Graphical Interface: The game is rendered in a window with a smooth display. The player can close the window with the ESC key or by clicking the window's close button.
Requirements
C programming: The project is implemented in C.
MiniLibX: A graphical library used to manage windows, handle keyboard/mouse events, and display images.
Makefile: A Makefile that compiles the source code with required flags (-Wall, -Wextra, -Werror) and avoids relinking.
Gameplay
The player starts at a specified position (P) on the map.
The goal is to move around the map, collect all collectibles (C), and reach the exit (E).
The player is restricted from moving through walls (1).
Every movement is counted, and the total number of movements is displayed in the shell.
The game must run smoothly, with proper handling of window events like minimizing or changing focus.
Map Structure
The map is defined in a .ber file and consists of:

A rectangular grid of characters.
At least one starting position (P), one collectible (C), and one exit (E).
The map must be surrounded by walls (1), and there must be a valid path between the starting position and the exit.
Error Handling
The program ensures that the map is valid and returns an error message if any issues (e.g., missing exit, invalid map structure) are found.
The program exits gracefully on encountering errors, displaying an appropriate message.

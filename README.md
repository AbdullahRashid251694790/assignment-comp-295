this assignment is for creating a game named 2048
in this game we combine tiles
our main goal is to combine tiles untill we get a 2048 tile
The program uses a 2D array "board" to represent the game grid, where each element represents the number on the tile in the corresponding position on the grid
The program starts by displaying a menu with options to start the game, see instructions, or quit.
Once the game is started, the program generates two random tiles (2 or 4) at the beginning of the game, and then after each move.The game is played by pressing keys 'u', 'd', 'l', or 'r' to move the tiles up, down, left, or right, respectively. 
The movement of tiles is done by shifting the tiles in the corresponding direction and combining the tiles with the same numbers. The program keeps track of the player's score, which is incremented by 2 after each successful move.
The program also checks for a win or loss condition after each move. The game is won when a tile with the number 2048 is created, and the game is lost when there are no more moves available or the grid is full.
The program uses several functions to implement the game logic, such as "space_check" to check if there are any empty spaces left on the grid, "addition_check" to check if there are any tiles that can be combined, "winner_check" to check if the player has won the game, and "print_func" to print the current state of the game grid.

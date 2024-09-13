Description
This is a simple project that implements the classic "X and 0" (Tic-Tac-Toe) game using the C programming language. In this game, the player competes against the computer, and who starts is decided by a dice roll. The player can choose to play with "X" or "0", and the rest of the game is played in turns, with each side selecting a position on the game board.

Features
Deciding who starts: Both the player and the computer roll a dice, and the one with the higher number starts.
Symbol selection: The player chooses whether to play with "X" or "0" if they start, and the computer gets the opposite symbol.
Interactive board: The player's moves are entered (row and column), and the board is updated after each turn.
Computer plays randomly: The computer chooses a random free position.
Winner detection: The game automatically detects when one of the players wins and displays the result.

How to run the game
Compilation: Use a C compiler to compile the code. For example, using gcc:
gcc -o tic_tac_toe tic_tac_toe.c
./tic_tac_toe

How to play
Dice roll: At the beginning, the player and the computer roll a dice to decide who starts. If the player rolls a higher number, they go first.
Symbol selection: If the player starts, they choose whether to play with "X" or "0". If the computer starts, the symbol is selected randomly.
Making moves: The player selects the row and column where they want to place their symbol. The board is updated, and then the computer makes its move.
Winner detection: After each move, the game checks if there is a winner. The game continues until a player wins or the board is full.
Score: After the game ends, the score is updated and the player is asked if they want to play again.
Code structure
firstPick(): Decides who starts the game by rolling a dice.
choice(): Determines the symbol ("X" or "0") based on who starts.
game(): Contains the main logic of the game, alternating between the player and the computer.
main(): Initializes the game and controls the main loop, providing the option to play again.

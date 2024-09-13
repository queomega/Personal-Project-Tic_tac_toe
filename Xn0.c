#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to determine who starts the game (player or computer) using a dice roll
int firstPick()
{
    int ok = 1;
    int playerChoice;
    int computerChoice;
    printf("Throw a dice to decide who starts: \n");
    sleep(1);
    
    // Loop until there is a winner (either player or computer rolls a higher number)
    while(ok == 1)
    {
        // Player throws the dice
        printf("Player throws the dice: \n");
        for(int i = 0; i < 3; i++)
        {
            sleep(1);
            printf(".");
            fflush(stdout);
        }
        sleep(1);
        printf("It lands on %d \n", playerChoice = (rand() % 6) + 1);  // Random dice result for player
        
        // Computer throws the dice
        printf("Computer throws the dice: \n");
        for(int i = 0; i < 3; i++)
        {
            sleep(1);
            printf(".");
            fflush(stdout);
        }
        sleep(1);
        printf("It lands on %d \n", computerChoice = (rand() % 6) + 1);  // Random dice result for computer
        
        sleep(2);
        
        // Determine who has a higher number
        if(playerChoice > computerChoice)
        {
            ok = 0;  // Player wins the dice roll
            return 1;
        }
        else if(playerChoice < computerChoice)
        {
            ok = 0;  // Computer wins the dice roll
            return 0;
        }
        else
        {
            printf("It's a draw, throw again! \n");  // Re-roll in case of a tie
        }
    }
    return 0;
}

// Function to decide if the player chooses 'X' or '0', and assigns the opposite to the computer
void choice(int playerStart, int computerStart, char *playerChoice, char *computerChoice)
{
    int ok = 1;
    
    // If player starts, they choose 'X' or '0'
    if(playerStart > computerStart)
    {
        while(ok == 1)
        {
            printf("Choose X or 0 ");
            scanf("%c", playerChoice);  // Take player input for 'X' or '0'
            
            // Validate player input
            if(*playerChoice != 'X' && *playerChoice != '0')
            {
                printf("Wrong input \n");
            }
            else
            {
                ok = 0;
            }
        }
        
        // Assign the opposite choice to the computer
        if(*playerChoice == 'X')
        {
            *computerChoice = '0';
        }
        else
        {
            *computerChoice = 'X';
        }
    }
    else
    {
        // If computer starts, randomly assign 'X' or '0'
        int random = rand() % 2;
        if(random == 0)
        {
            *computerChoice = '0';
            *playerChoice  = 'X';
        }
        else
        {
            *computerChoice = 'X';
            *playerChoice = '0';
        }
    }
}

// Main game function where the player and computer take turns marking the board
int game(char playerChoice, char computerChoice, int playerStart, int computerStart, char table[3][3])
{
    srand(time(NULL));  // Seed random number generator
    for(int k = 0; k < 9; k++)  // Maximum 9 moves (3x3 grid)
    {
        int linie;
        int coloana;
        int ok = 0;
        
        // If player starts, player takes their turn first
        if(playerStart > computerStart)
        {
            printf("\nPlayer turn: \n");
            sleep(1);
            
            // Loop until the player selects an empty cell
            while(ok == 0)
            {
                printf("Enter a line: ");
                scanf("%d", &linie);  // Get row
                printf("Enter a column ");
                scanf("%d", &coloana);  // Get column
                
                // Check if the chosen cell is empty
                if(table[linie - 1][coloana - 1] == ' ')
                {
                    table[linie - 1][coloana - 1] = playerChoice;  // Place player's mark
                    ok = 1;
                }
                else
                {
                    printf("Space is occupied \n");
                }
                computerStart += 2;
            }
            
            // Display the updated game board
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    printf(" %c ", table[i][j]);
                    if(j < 2)
                    {
                        printf("|");
                    }
                }
                printf("\n");
                if(i < 2)
                {
                    printf("---|---|---\n");
                }
            }
            
            // Check if the player has won
            for(int i = 0; i < 3; i++)
            {
                if(table[i][0] == playerChoice && table[i][1] == playerChoice && table[i][2] == playerChoice)
                {
                    printf("\nPlayer wins!\n");
                    return 1;
                }
                else if(table[0][i] == playerChoice && table[1][i] == playerChoice && table[2][i] == playerChoice)
                {
                    printf("\nPlayer wins!\n");
                    return 1;
                }
                else if(table[0][0] == playerChoice && table[1][1] == playerChoice && table[2][2] == playerChoice)
                {
                    printf("\nPlayer wins!\n");
                    return 1;
                }
                else if(table[0][2] == playerChoice && table[1][1] == playerChoice && table[2][0] == playerChoice)
                {
                    printf("\nPlayer wins!\n");
                    return 1;
                }
            }
        }
        else  // Computer's turn
        {
            printf("\nComputer turn: \n");
            sleep(2);
            
            // Computer randomly selects an empty cell
            while(ok == 0)
            {
                linie = rand() % 3;
                coloana = rand() % 3;
                if(table[linie][coloana] == ' ')
                {
                    table[linie][coloana] = computerChoice;  // Place computer's mark
                    ok = 1;
                }
            }
            playerStart += 2;
            
            // Display the updated game board
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    printf(" %c ", table[i][j]);
                    if(j < 2)
                    {
                        printf("|");
                    }
                }
                printf("\n");
                if(i < 2)
                {
                    printf("---|---|---\n");
                }
            }
        }
        
        // Check if the computer has won
        for(int i = 0; i < 3; i++)
        {
            if(table[i][0] == computerChoice && table[i][1] == computerChoice && table[i][2] == computerChoice)
            {
                printf("\nComputer wins!\n");
                return 0;
            }
            else if(table[0][i] == computerChoice && table[1][i] == computerChoice && table[2][i] == computerChoice)
            {
                printf("\nComputer wins!\n");
                return 0;
            }
            else if(table[0][0] == computerChoice && table[1][1] == computerChoice && table[2][2] == computerChoice)
            {
                printf("\nComputer wins!\n");
                return 0;
            }
            else if(table[0][2] == computerChoice && table[1][1] == computerChoice && table[2][0] == computerChoice)
            {
                printf("\nComputer wins!\n");
                return 0;
            }
        }
    }
    return 0;
}

// Main function to control the game flow
int main()
{
    int ok = 1;
    int playerScore = 0;
    int computerScore = 0;
    char playerChoice = ' ';
    char computerChoice = ' ';
    
    {
        int playerStart = 0;
        int computerStart = 0;
        printf("Play a game of X and 0 \n");
        
        // Decide who starts
        if(firstPick())
        {
            printf("Player starts! \n");
            playerStart++;
        }
        else
        {
            printf("Computer starts! \n");
            computerStart++;
        }
        
        // Initialize the game board
        char table[3][3];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                table[i][j] = ' ';
            }
        }
        
        // Player or computer chooses 'X' or '0'
        choice(playerStart, computerStart, &playerChoice, &computerChoice);
        
        // Start the game
        if(game(playerChoice, computerChoice, playerStart, computerStart, table))
        {
            playerScore++;
        }
        else
        {
            computerScore++;
        }
        
        // Display the score
        printf("\n Score \n Player: %d Computer: %d \n", playerScore, computerScore);
        
        // Ask if the player wants to play again
        printf("Play again? (Y/N) ");
        char again = 'a';
        scanf(" %c", &again);
        while(getchar() != '\n');
        
        if(tolower(again) != 'y')
        {
            ok = 0;
        }
        printf("\n");
    }
    return 0;
}

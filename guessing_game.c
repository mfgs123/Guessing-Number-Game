/*
Program Description: Guessing Game where user has to guess one number between 1 and 25, the user has 5 attempts. If these 5 attempts are reached,
the game will automatically end. Everytime the user enters a number, the game will let the user know if
the number is too high or low. If the game is won or maximum attempts are reached, the program
will print the number of attempts the user did and their guess history.
*/

#include <stdio.h>
#include <stdlib.h> // this header file is required for the rand() function
#include <time.h> // used in srand() for seeding purposes

#define MAX_ATTEMPTS 5

int main()
{
    int num = 0;
    int guessHistory[MAX_ATTEMPTS];
    int userguess [MAX_ATTEMPTS];
    int attempts = 0;
    int i;
    // place any extra variables here
    printf("This is a game where you have to guess a number between 1 and 25. You have 5 attempts\n");
    printf("Generating a random number between 1 and 25 \n");
    
    // seed the random number generator with a range 0 – large number
    srand(time(NULL));
    
    // num is assigned a random number between 1 – 10 
    num = (rand() % 25) + 1;
    
    //creating  a loop so that user can enter numbers 5 times

    for (i=0 ; i<MAX_ATTEMPTS ; i++) //start main for loop to enter numbers
    {
        printf("\nPlease enter a number: ");
        scanf("%d", &userguess[i]);

        if(userguess[i] >= 1 && userguess[i] <=25) // if statement to make sure user enters valid numbers
        {

            if (userguess[i] != num) //if loop for if user guesses incorrectly
            {
              printf("\nSorry you didnt guess the number");
              attempts = attempts + 1; //counter for number of attempts
              guessHistory[i] = userguess[i];

               if (userguess[i] < num) //inner if loop if guess is too low
                {
                   printf("\nYour guess is too low");
                }//end inner if loop

               if (userguess[i] > num)// inner if loop if guess is too high
                {
                  printf("\nYour guess is too high");
                } //end inner if loop

            }//end first if loop

            //if loop if user guesses number correctly
            if(userguess[i] == num)
            { 
               printf("\nCongratulations, you guessed the number correctly");
               attempts = attempts + 1;
               guessHistory[i] = userguess[i];
               i = 5; // so the program immediately ends
            }//end  if loop

        }//end outer if statement

    }// end main for loop

    //printf to display number of attempts and guess history
    printf("\n\nProgram finished. Your number of attempts is %d.\nThis is your guess history: ", attempts);

    //start for loop to diplay guess history
    for(i=0 ; i<attempts ; i++)
    {
        printf("\n%d", guessHistory[i]);
    }//end for loop
    
    return 0;
    
} // end main
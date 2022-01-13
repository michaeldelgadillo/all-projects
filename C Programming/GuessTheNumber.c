/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 21 Febuary 2019
Project Name: Guess the Number
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numberOfGuesses=10, guess, i;

    /* Use current time as seed for random generator */
	srand(time(0));

	/*Creates a secret random number from 1-100*/
	int secretNumber = rand() % 100 + 1;

	/*Instructions and number of Turns.*/
	printf("You have 10 tries to guess the secret number from 1-100.\n");

	/*For loop used to collect users guest and compare it against the random number.
	Additionally, tells the user to guess lower or higher, and also tells them how
	many tries they have left*/
	for(i = 0; i <= 9 && guess != secretNumber; i++)
	{
	    /*Verifies that the user only inputs a value from 1-100*/
	    do
	    {
	    	scanf("%i", &guess);
	    }
	    while(guess < 1 || guess > 100);

	    numberOfGuesses--;

	    if(guess < secretNumber && numberOfGuesses != 0)
	    {
	        printf("Try guessing higher. Tries left: %i.\n", numberOfGuesses);
	    }
	    if(guess > secretNumber && numberOfGuesses != 0)
	    {
	        printf("Try guessing lower. Tries left: %i.\n", numberOfGuesses);
	    }
	}

    /*This section contains other messages such as a Loser message, and 2 winner messages*/
	if(numberOfGuesses == 9)
	{
	    printf("You're a mind reader! You guessed the secret number on your first try!\n");
	}
	else if(guess == secretNumber)
	{
	    printf("Winner Winner, Chicken Dinner! You guessed the secret number in %i tries!\n", 10 - numberOfGuesses);
	}
	else
	{
	    printf("No more tries left, you lose! The secret number was %i.\n", secretNumber);
	}

    return 0;
}
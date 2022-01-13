/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 21 Febuary 2019
Project Name: Lottery
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int favoriteNumber=0, lotteryNumbers[365] = {0}, i, timesWon;
    char buyTicket;
    float moneyWon = 0.00, prizeMoney = 500.00;

    /* Use current time as seed for random generator */
    srand(time(0));

    /*Prompts the User to purchase 365 tickets worth $1.00 Each*/
    printf("Would you like to purchase one year of lottery tickets for $365.00($1.00 each)? Y=Yes/N=NO\n");
    scanf("%c", &buyTicket);

    /*Program will continue further only if user agrees to buy tickets*/
    if(toupper(buyTicket) == 'Y')
    {
        /*Asks for user's favorite number*/
        printf("What's your favorite number?(000-999 only)\n");
        do
        {
            scanf("%i", &favoriteNumber);
        }
        while(favoriteNumber < 0 || favoriteNumber > 999);

        /*Generates Random Number from 000-999 and compares it to the User's
        favoriteNumber.*/
        for(i = 0 ; i < 365; i++)
        {
            lotteryNumbers[i] = rand() % 999;
        }

        /*Check the user's favorite number against all of the newly generated
        lottery numbers, essentially playing for a year and counting each
        time the user wins*/
        for(i = 0; i < 365; i++)
        {
            if(lotteryNumbers[i] == favoriteNumber)
            {
                timesWon++;
            }
        }

        /*Multiplies Number of times won with the prize $500.00, displays favorite Number
        and the amount of money won.*/

        printf("Thanks for playing, here are the final results of the lottery.\n");

        /*Displays a special message if they won at least once*/
        if(timesWon>0)
        {
            printf("Congratulations You Won!\n");
        }
        printf("Favorite Number:\t%03i\n", favoriteNumber);
        printf("Number of Times Won:\t%i\n", timesWon);
        printf("Total Prize Money:\t$ %.2f\n", timesWon*prizeMoney);
    }

    return 0;
}
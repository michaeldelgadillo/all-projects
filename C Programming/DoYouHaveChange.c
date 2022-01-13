/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 13 February 2019
Project Name: Do You Have Change?
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    /* Use current time as seed for random generator */
	srand(time(0));


	/*This for loop generates a Random Number, initializes the coins, counts the coins and then Prints out each iteration*/
	for(int i = 0; i<25; i++){

		/*This section contains and initializes the different coins*/
		int penny = 0;
		int nickel = 0;
		int dime  = 0;
		int quarter = 0;
		int half  = 0;
		int changeLeft = 0;

		/*Combines the seed number generated from srand and time to create a variable from 1 to 99*/
		int generateRandomChange = rand() % 100 + 1;

		/* Stores the Value in a temporary value called "change" used to be manipulated in the code */
		int change = generateRandomChange;

	/* Checks the random change, counts each time each coin amount, then subtracts and repeats until randomChange is 0*/
        do
        {
		if(change >= 50){
    	        half = change / 50;
    	        change = change % 50;
        	}else if(change >= 25){
        	    quarter = change / 25;
        	    change = change % 25;
        	}else if(change >= 10){
        	    dime = change / 10;
        	    change = change % 10;
        	}else if(change >= 5){
        	    nickel = change / 5;
        	    change = change % 5;
        	}else if(change >= 1){
                penny = change;
                change = 1 % 1;
        	}else if(change == 0){
        	    changeLeft = 1;
        	}

        }
        while(changeLeft == 0);

        /* Prints out the number of coins for each Iteration of the Loop after it's done counting*/
        printf("%i cents, ", generateRandomChange);

        /*Verifies, formats and prints out only the necessary values if greater than 0 for each coin*/
        if(half >= 1){
            printf("%i Half, ", half);
        }
        if(quarter == 1){
            printf("%i Quarter, ", quarter);
        }
        else if(quarter > 0){
            printf("%i Quarters, ", quarter);
        }

        if(dime == 1){
            printf("%i Dime, ", dime);
        }else if(dime > 1){
            printf("%i Dimes, ", dime);
        }

        if(nickel == 1){
            printf("%i Nickel, ", nickel);
        }
        else if(nickel > 1){
            printf("%i Nickels, ", nickel);
        }

        if(penny == 1){
            printf("%i Penny", penny);
        }
        else if(penny > 1){
            printf("%i Pennies", penny);
        }

        printf("\n");

	}
    return 0;
}
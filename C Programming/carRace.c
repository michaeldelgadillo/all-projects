/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 21 March 2019
Project Name: carRace
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define FLUSH myFlush()

//This section contains all the functions
void myFlush();
void pause(int);
void welcome();
void raceBegin();
char promptRaceAgain();

int main()
{
    char raceAgain; //Simple Do while loop to keep the race going until user quits
    do{
        welcome(); //displays welcome message
        raceBegin();
        raceAgain = promptRaceAgain(); FLUSH;
    }while(raceAgain != 'N');
    return 0;
}

//This section asks the user if they would like to race again
char promptRaceAgain(){
    char raceAgain;
    printf("Would you like to race again?(Y/N)\n");
    scanf(" %c", &raceAgain);
    fflush(stdin);
    raceAgain = toupper(raceAgain);
    system("clear");
    return raceAgain;
}

//clears the keyboard buffer
void myFlush(){
	while(getchar() != '\n');
}

//Create a pause to simulate a wait time
void pause(int inNum){
    int iCurrentTime = 0;
    int iElapsedTime = 0;
    iCurrentTime = time(NULL);
    do {
        iElapsedTime = time(NULL);
    } while ((iElapsedTime - iCurrentTime)< inNum);
}
//Begins the race
void raceBegin(){
    int race=80; //race ends once any of the cars reach 80
    int a = 1, b = 1, c = 1;
    char *first, *second, *third;
    srand(time(NULL)); //Used to generate a random time

    //Initializes the letters in the start of the race
    printf("A\n");
    printf("B\n");
    printf("C\n");

    while(a<race && b<race && c<race)
    {
        int randomCar = (rand() % 3) + 1; //Randomly selects a car from 1-3
        int randomMoves = (rand() % 3) + 1;//Randomly selects the number of spaces
        system("clear");
        printf("\t\t\t\t\t\t\t\t\t       |Finish\n");//Finish line displayed at all times


        if(randomCar == 1)
        {
            if(race >= (a + randomMoves))
            {
               a += randomMoves;
            }
        }

        if(randomCar == 2)
        {
            if(race >= (b + randomMoves))
            {
               b += randomMoves;
            }
        }

        if(randomCar == 3)
        {
           if(race >= (c + randomMoves))
            {
               c += randomMoves;
            }
        }

        //As the values of the cars increase, the print more letters until one reaches 80

        for(int j = 0; j < a; j++)
        {
            printf("A");
        }
        printf("\n");
        for(int k = 0; k < b; k++)
        {
            printf("B");
        }
        printf("\n");
        for(int l = 0; l < c; l++)
        {
           printf("C");
        }
        printf("\n");

        pause(1);

    }
    //Checks to see what position the car is in based on the value
    if(a>b && a>c)
    {
        first = "A";
    }
    else if (a>b || a>c)
    {
        second = "A";
    }
    else
    {
        third = "A";
    }

    //
    if(b>a && b>c)
    {
        first = "B";
    }
    else if (b>a || b>c)
    {
        second = "B";
    }
    else
    {
        third = "B";
    }

    //
    if(c>b && c>a)
    {
        first = "C";
    }
    else if (c>b || c>a)
    {
        second = "C";
    }
    else
    {
        third = "C";
    }
    //Sometimes two letters will reach equal amounts of spaces so we have a tie
    if(a == b)
    {
        second = "Tie";
        third = "Tie";
    }
    else if(a == c)
    {
        second = "Tie";
        third = "Tie";
    }
    else if(c == b)
    {
        second = "Tie";
        third = "Tie";
    }

    printf("\n"); //Prints out the final results of the race

    printf("***************************\n");
    printf("** Race Winner is.: %s  **\n", first);
    printf("** Second place is: %s  **\n", second);
    printf("** Race loser is..: %s  **\n", third);
    printf("***************************\n");
}

//Welcome message at the start of every race
void welcome(){
    char detectKey;
    printf("==========================\n");
    printf("Welcome to Mike's Raceway \n");
    printf("==========================\n");

    printf("Press Enter to Begin:\n");
    detectKey = getchar();
}

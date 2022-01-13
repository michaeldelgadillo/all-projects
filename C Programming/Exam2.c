/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pause(int);

int main()
{
    int race=15;
    int a = 1, b = 1, c = 1;
    int sortCars[3] = {0};
    int noPlayers = 4;

    srand(time(NULL));

    printf("A\n");
    printf("B\n");
    printf("C\n");

    while(a<race && b<race && c<race)
    {
        int randomCar = (rand() % 3) + 1;
        int randomMoves = (rand() % 3) + 1;
        system("clear");
        printf("                            |Finish\n");


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

        printf("Car A:%i\n",a);
        printf("Car B:%i\n",b);
        printf("Car C:%i\n",c);

        pause(1);

    }



    return 0;


}

void pause(int inNum)
{
    int iCurrentTime = 0;
    int iElapsedTime = 0;
    iCurrentTime = time(NULL);
    do {
        iElapsedTime = time(NULL);
    } while ((iElapsedTime - iCurrentTime)< inNum);
}

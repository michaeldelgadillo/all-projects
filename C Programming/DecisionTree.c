/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 28 January 2019
Project Name: Decision Tree
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*This section contains all the inputs for the code below*/
    char inputOne[2];
    char inputTwo[2];
    char inputThree[2];

    /*This section collects all of the required information from the user*/
    printf("Welcome to Decision Statement. Please enter 3 characters, 1 at a time and press enter.\n");
    printf("Character 1:\n");
    scanf("%s", inputOne);
    printf("Character 2:\n");
    scanf("%s", inputTwo);
    printf("Character 3:\n");
    scanf("%s", inputThree);

    /*This Check the input from the User using a loop*/
    if(inputOne[0] == inputTwo[0] && inputThree[0] != 'z') {
        printf("Happy\n");
    } else if(inputOne[0] < inputTwo[0] && inputOne[0] < inputThree[0]) {
        printf("Sad\n");
    } else {
        printf("Dead\n");
    }

    return 0;
}
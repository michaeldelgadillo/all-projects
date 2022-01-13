/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 9 March 2019
Project Name: Function Menu
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int userMenu();
void returnToMain();
void userTasks(int);


int main()
{
    //This is where the program begins
    userMenu();
    return 0;
}

int userMenu()
{
    //This section contains all of the options to choose from
    int selection;
    do
    {
        system("cls");
        printf("Choose from the following options:\n");
        printf("1. Display Your Name\n");
        printf("2. Display Your Name (10 Times)\n");
        printf("3. Display Add Two Numbers\n");
        printf("4. Take the Result of item 3 above and square it\n");
        printf("5. Quit\n");
        printf("Selection(1-5):");
        scanf("%i", &selection);
    }
    while (selection > 5 || selection < 1);
    userTasks(selection);//Using "Inception" a function within a function to loop until user quits
}

//This section takes in the selection from the userMenu and processes it through a switch
void userTasks(int selection)
{
    system("cls"); //clears the screen
    int numOne = 5, numTwo = 8; //Numbers used for Adding 2 numbers
    int sum = numOne + numTwo; //Sum of the two numbers that will be squared

    switch(selection)
    {
        case 1 : //Displays My Name 1 time
        printf("Michael Delgadillo\n\n");
        returnToMain();
        break;
        case 2 : //Display My Name 10 times using a for loop to save code
        for(int i = 1; i <= 10; i++)
        {
            printf("%i. Michael Delgadillo\n", i);
        }
        printf("\n");
        returnToMain();
        break;
        case 3 : //This section adds the two variables numOne & numTwo
        printf("The sum of %i + %i = %i\n\n", numOne, numTwo, sum);
        returnToMain();
        break;
        case 4 ://This section squares the sum of the two variable in step 3
        printf("The Squared result of #3 = %i\n\n", sum*sum);
        returnToMain();
        break;
        default : //same as selection 5, this option is used to quit.
        break;
    }
}

//The purpose of this function is to give the user the option to return to the Main Menu
void returnToMain()
{

    int goToMainMenu = 0;

    printf("Return to Main Menu?\n");
    printf("1: Yes / 2: No\n");
    printf("Selection(1-2):");

    do
    {
        scanf("%i", &goToMainMenu);
    }
    while(goToMainMenu > 2 || goToMainMenu < 1);


    if(goToMainMenu == 1)
    {
        system("cls");
        userMenu();
    }
}


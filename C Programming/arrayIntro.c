/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 21 March 2019
Project Name: arrayIntro
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define CLS system("clear")
#define PAUSE getchar()

//These are all the functions in the program
int getChoice();
int * getNumbers();
int getSize();
void mainMenu();
void printAll();
void sumAll();
void averageAll();

int main()
{
    int howMany; // Stores the quantity of numbers user will enter in numbers array
    int userChoice; //Stores User's choice for menu
    int *numbers; //stores the number the user enters
    do{
        mainMenu();
        userChoice = getChoice();
        switch(userChoice){
            case 1: //Get Numbers From User
                howMany = getSize();
                numbers = getNumbers(howMany);
                break;
            case 2:
                sumAll(numbers, howMany); //adds all the numbers stored in the array
                break;
            case 3:
                averageAll(numbers, howMany); //finds the average of all the numbers stored in the array
                break;
            case 4:
                printAll(numbers, howMany); //Displays all the numbers as entered by the user
                break;
            case 5:
                printf("You have exited the program.\n"); //notifies the user that they have exited the program
                break;
            default:
                CLS;
                break;
        }
    }while(userChoice != 5);

    return 0;
}
//This section captures and returns the user's choice from the menu options
int getChoice(){
    int choice;
        printf("Enter selection:");
        scanf("%i", &choice);
        return choice;

}

//This section store the numbers the user enters up to 1000
int * getNumbers(int howMany)
{
    int howManyNums = howMany;
    static int numbers[1000];
    printf("Please Enter %i Numbers\n", howManyNums);
    for(int i = 0; i < howManyNums; i++){
        printf("%i. ",i+1);
        scanf("%i",&numbers[i]);
    }
    CLS;
    return numbers;
}

//This section asks the user how many numbers they would like to enter up to 1000
int getSize(){
    int howMany;
    do{
        CLS;
        printf("How many numbers will you enter?(Up to 1000)\n");
        scanf("%i", &howMany);
    }while (howMany < 1 || howMany > 1000);
    CLS;
    return howMany;
}

//This section finds the average of all the numbers entered in step 1
void averageAll(int *numbers, int howMany){
    int sum = 0;
    float avg = 0;
    for(int i = 0; i < howMany; i++)
    {
        sum += *(numbers + i);
    }
    avg = (float) sum/howMany;
    printf("Average is %.2f\n", avg);
    getchar();
    PAUSE;
    CLS;
}
//This is the main menu
void mainMenu(){
    printf("*************************\n");
    printf("**      Main Menu      **\n");
    printf("*************************\n");
    printf("1. Enter a number\n");
    printf("2. Display the Sum of all numbers entered\n");
    printf("3. Display Average of Numbers entered\n");
    printf("4. Display all numbers entered\n");
    printf("5. Quit\n");
}

//Displays the numbers as entered by the user in step 1
void printAll(int *numbers, int howMany){
    CLS;
    printf("You Entered:\n");
    for (int i = 0; i < howMany; i++ ){
        printf( "%i. %i\n", i+1, *(numbers + i));
    }
    getchar();
    PAUSE;
    CLS;
}

//This section finds the sum of all the numbers entered in step 1
void sumAll(int *numbers, int howMany){
    int sum = 0;
    for(int i = 0; i < howMany; i++)
    {
        sum += *(numbers + i);
    }
    printf("Sum is %i\n",sum);
    getchar();
    PAUSE;
    CLS;
}

/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 10 April 2019
Project Name: sortSearch
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FLUSH myFlush()//clears the keyboard buffer after input
#define SIZE 100 //sets the default array size, allowing changes in the array to be quick
#define CLS system("clear"); //clears the screen to avoid clutter

//This section prototype the functions being used in the program
char getChoice();
void checkGPA();
void displayAdjustedAverage();
void displayAllGPA();
void displayAverage();
void displayHighGPA();
void displayLowGPA();
void getGPA();
void mainMenu();
void myFlush();
void sortGPA();


int main()
{
    //These two variables declare an array and variable for user choice
    float arrayGPA[SIZE] = {0};//Array will continue to store GPA's up until size is reached.
    char choice;

    //Using a Do While loop to keep the menu going until user quits the program
    do{
        choice = getChoice(); //get the user's choice and stores it in a char called choice
        switch(choice){ //Switch statement uses the choice to perform the appropriate functions
            case 'A':
                getGPA(arrayGPA); //This section gets the User's GPA and stores it in the array
                break;
            case 'B':
                displayAverage(arrayGPA); //This section get the average of the GPA's in the arrays entered
                break;
            case 'C':
                sortGPA(arrayGPA); //This function Sorts the array from least to greatest
                displayHighGPA(arrayGPA); //This function looks for the highest number in the array
                break;
            case 'D':
                sortGPA(arrayGPA);
                displayLowGPA(arrayGPA); //This function looks for the highest number in the array
                break;
            case 'E':
                sortGPA(arrayGPA);
                displayAdjustedAverage(arrayGPA); //This function drops the lowest number and then finds the average
                break;
            case 'F':
                checkGPA(arrayGPA); //This is the search function used to find if GPA exists
                break;
            case 'G':
                sortGPA(arrayGPA);
                displayAllGPA(arrayGPA); //This section displays all the GPAs entered at the moment
                break;
            case 'Q':
                printf("\nYou have exited the program.\n");
                break;
            default:
                printf("\nInvalid menu selection.\n");
                getchar();
                break;
        }
    }while(choice != 'Q'); //Ends if user selects Q

    return 0;
}

//This sections prompts the user to enter a choice from the menu
char getChoice(){
    char choice;
    mainMenu();
    scanf("%c", &choice); FLUSH;
    choice = toupper(choice); //Makes the character uppercase to allow for both upper and lower reponses
    return choice;
}
//This is a Search function that checks if GPA Exists
void checkGPA(float arrayGPA[]){
    int found = -1; //Uses a true false type verifer
    int i;
    float checkGPA;
    if(arrayGPA[0] != '\0'){ //Verifies that the array is not empty
        printf("Enter GPA and hit Enter to Search: ");
        scanf("%f", &checkGPA); FLUSH;
        for(i = 0; arrayGPA[i] != '\0';i++){ //Ends the search when it reaches the last value in the array versus looping "SIZE-1" Times
            if(arrayGPA[i] == checkGPA){     //This allows for a faster search especially with smaller inputs
                found = 1;
                break;
            }
        }
        if(found == 1){
                printf("\nGPA %.2f found at arrayGPA[%i].\n", checkGPA, i);
            }else{
                printf("\nGPA has not been entered.\n"); //If GPA is not found in the search
            }
    }else{
        printf("\nPlease enter some GPA's first.\n");// If array is empty user is prompted to enter values
    }
    getchar();
}
//Adjusted average drops the lowest score, then performs the Average Equation
void displayAdjustedAverage(float arrayGPA[]){
    int i=1; //Since the array is sorted before reaching this function, the lowest value is located at index 0 and dropped
    float addNums = 0.0;
    if(arrayGPA[0] != '\0' && arrayGPA[1] != '\0'){ //A minimum of 2 values must be met before the function moves further
        while(arrayGPA[i] != '\0' && i < SIZE){ //Faster than using SIZE-1, loops ends at the end of the array of GPAs entered
        addNums += arrayGPA[i];
        i++;
        }
        printf("\nAdjusted average of all GPA's: %.2f\n", addNums/(i-1)); //average formula after dropping the lowest value
    }else{
        printf("\nPlease enter a minimum of 2 GPA's to get the adjusted average.\n");
    }
    getchar();
}
//this section displays all of the GPA's in ascending order
void displayAllGPA(float arrayGPA[]){
    int i=0;
    if(arrayGPA[0] != '\0'){
        printf("\nCurrent GPA's entered.\n");
        while(arrayGPA[i] != '\0' && i < SIZE){
            printf("%i. %.2f\n", i, arrayGPA[i]); //Loops through array and displays the values stored
            i++;
        }
    }else{
        printf("\nPlease enter some GPA's first.\n");
    }
    getchar();
}
//Displays the average of all GPAs entered into the array
void displayAverage(float arrayGPA[]){
    int i = 0;
    float addNums = 0.0;
    if(arrayGPA[0] != '\0'){//First checks to make sure array isn't empty
        while(arrayGPA[i] != '\0' && i < SIZE){
        addNums += arrayGPA[i];
        i++;
        }
        printf("\nAverage of all GPA's: %.2f\n", addNums/i);
    }else{
        printf("\nPlease enter some GPA's first.\n");
    }
    getchar();
}
//Finds the highest GPA entered in the array
void displayHighGPA(float arrayGPA[]){
    int i = 0;
    if(arrayGPA[0] != '\0'){//verifies that the Array is not empty
        while(arrayGPA[i] != '\0' && i < SIZE){//after array is sorted, it finds and selects the last number in the array
        i++;
        }
        printf("\nHighest GPA: %.2f\n", arrayGPA[i-1]); //Displays the highest value in the array
    }else{
        printf("\nPlease enter some GPA's first.\n");
    }
    getchar();
}
//Finds the lowest GPA entered in the array
void displayLowGPA(float arrayGPA[]){
    if(arrayGPA[0] != '\0'){//verifies the array is not empty
        printf("\nLowest GPA: %.2f\n", arrayGPA[0]);//After array is sorted in ascending order it selects index 0 as the lowest
    }else{
        printf("\nPlease enter some GPA's first.\n");
    }
    getchar();
}

//Gets GPA inputs from the user accepts floats
void getGPA(float arrayGPA[]){
    int i=0;
    while(arrayGPA[i] != '\0' && i < SIZE){ //searches for the next empty spot in the array and allows for user input
        i++;
    }
    if(i < SIZE){//verifies that the next available spot is not equal or greater than the max size
        printf("\nPlease enter a GPA: ");
        scanf("%f", &arrayGPA[i]); FLUSH;
        if(arrayGPA[i] < 2.0){ //Displays a message depending on the user's input
            printf("\nYou need to study harder!\n");
            getchar();
        }
        if(arrayGPA[i] > 3.5){
            printf("\nNice Work!\n");
            getchar();
        }
    }else{
        printf("\nERROR: Memory Full!\n");//Once the array is full, the user can no longer enter values
        printf("No more GPA's can be entered at this time.\n");
        getchar();
    }
}

//This section contains the main menu, which lines up with the functions and the switch statement
void mainMenu(){
    CLS;
    printf("********************************\n");
    printf("******      Main Menu     ******\n");
    printf("********************************\n");
    printf("A. Enter GPA\n");
    printf("B. Display Average of all GPA's\n");
    printf("C. Display the Highest GPA\n");
    printf("D. Display the Lowest GPA\n");
    printf("E. Display the adjusted average\n");
    printf("F. See if a certain GPA was entered\n");
    printf("G. Display the contents of the Array\n");
    printf("Q. Quit\n");
    printf("********************************\n");
    printf("Enter your selection: ");
}

//clears the keyboard buffer.
void myFlush(){
	while(getchar() != '\n');
}
//Sorts the GPA
void sortGPA(float arrayGPA[]){
    float tmp;//holds the value to be switched temporarily
    int i=0, j = 0, n = 0;
    while(arrayGPA[n] != '\0' && n < SIZE){//find out how big the array is at the moment
        n++;
    }
    for (i = 0; i < n; i++){//loops x times until less than n (size of the filled array)
       for (j = 0; j < n - i - 1; j++){//loop that compares each value to the next except the last
            if (arrayGPA[j] > arrayGPA[j + 1] && arrayGPA[j] > 0){//value, which will be the highest at the end of the first pass
               tmp = arrayGPA[j]; //if values being compared are out of order, they are swapped using a temp variable
               arrayGPA[j] = arrayGPA[j + 1];
               arrayGPA[j + 1] = tmp;
           }
       }
   }
}
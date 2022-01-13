/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 10 April 2019
Project Name: theElection
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FLUSH myFlush() //clears the keyboard buffer after input
#define SIZE 50 //sets the default array size - 50 states
#define CLS system("clear")

//this is where the functions are prototyped
int getChoice();
void cloneUnsorted();
void compareByState();
void displayAverage();
void displayVotes();
void displayLowHigh();
void getVotes();
void mainMenu();
void myFlush();
void sortVotes();

int main()
{

    int ivankaTrump[SIZE] = {0}, michelleObama[SIZE] = {0};//used for everything else
    int ivankaT[SIZE] = {0}, michelleO[SIZE] = {0};//Copy of above arrays used for the sorted step 4
    int choice;

    do{
        choice = getChoice();
        switch(choice){
            case 1:
                getVotes(ivankaTrump);//function to get votes from candidate
                break;
            case 2:
                getVotes(michelleObama);//function to get votes from candidate
                break;
            case 3:
                displayVotes(ivankaTrump, michelleObama);//Unsorted display total votes for each candidate
                break;
            case 4:
                cloneUnsorted(ivankaT,ivankaTrump, michelleO, michelleObama);//Display Total Votes Sorted
                sortVotes(ivankaT);
                sortVotes(michelleO);
                displayVotes(ivankaT, michelleO); //Displays the votes in a sorted fashion without altering the order of
                break; //the original values. Without this, step 3 would no longer work as intended.
            case 5:
                compareByState(ivankaTrump, michelleObama);//Displays state number(s) where Trump and Obama received same # of votes
                break;
            case 6:
                //For each candidate display the Highest & Lowest number of votes from any state
                displayLowHigh(ivankaTrump, michelleObama);
                displayAverage(ivankaTrump, michelleObama);
                break;
            case 7:
                printf("\nElection is over, Exit the program.\n");
                break;
            default:
                printf("\nInvalid menu selection.\n");
                getchar();
                break;
        }
    }while(choice != 7); //Ends if user selects Q

    return 0;
}
//This sections prompts the user to enter a choice from the menu
int getChoice(){
    int choice;
    mainMenu();
    scanf("%i", &choice); FLUSH;
    return choice;
}

//step 3 is displayed unsorted, so a clone of the arrays are made to be used in step 4 sorted array
void cloneUnsorted(int ivankaT[], int ivankaTrump[], int michelleO[], int michelleObama[]){
    int i = 0, j = 0, n = 0, m =0;
    while(ivankaTrump[n] != '\0' && n < SIZE){//find out how big the array is at the moment
        n++;
    }
    while(michelleObama[m] != '\0' && m < SIZE){//find out how big the array is at the moment
        m++;
    }
    for(i = 0; i < n; i++) {
      ivankaT[i] = ivankaTrump[i]; //clones each value to it's corresponding place in the new array
    }
    for(j = 0; j < m; j++){
        michelleO[j] = michelleObama[j]; //clones each value to it's corresponding place in the new array
    }
}

//checks to see in which states the candiates got the same amount of votes
void compareByState(int candidateOne[],int candidateTwo[]){
    int i = 0, match = 0;
    if(candidateOne[0] == '\0' && candidateTwo[0] == '\0'){
        printf("No votes have been entered yet, enter votes first\n"); //verifies input exists for either president
    }else{
        CLS;
        while(candidateOne[i] != '\0' && candidateTwo[i] != '\0'){
            if(candidateOne[i] == candidateTwo[i]){
                printf("Obama and Trump each got %i votes from state %i.\n", candidateOne[i], i);
                match = 1; //if at least one match is found, no error message is displayed.
            }
            i++;
        }
        if(match == 0){
        printf("No matches found."); //Displays error if conditions have not been met
        }
    }
    getchar();
}

//Finds the Average Number of Votes For Candidate One
void displayAverage(int candidateOne[], int candidateTwo[]){
    int i, m = 0, average = 0;

    //Finds the Average Number of Votes For Candidate One
    if(candidateOne[0] != '\0'){
        while(candidateOne[m] != '\0' && m < SIZE){//find out how big the array is at the moment
            m++;
        }
        for(i = 0; i < m ; i++){
            average += candidateOne[i]; //adds the current value until the loop finishes
        }
        printf("Average number of votes for Ivanka Trump is %i.\n", average/m); //divides by the numbers in the array at the moment
    }

    m = 0; //reset for reuse
    average = 0; //reset for reuse

    //Finds the Average Number of Votes For Candidate Two
    if(candidateTwo[0] != '\0'){
        while(candidateTwo[m] != '\0' && m < SIZE){//find out how big the array is at the moment
            m++;
        }
        for(i = 0; i < m ; i++){
            average += candidateTwo[i];
        }
        printf("Average number of votes for Michelle Obama is %i.\n", average/m);
    }
    getchar();
}
//displays both the highs and the lows for both candidates
void displayLowHigh(int candidateOne[], int candidateTwo[]){
    int highestOne = candidateOne[0], highestTwo = candidateTwo[0];
    int lowestOne = candidateOne[0], lowestTwo = candidateTwo[0];
    int i, j, m = 0, n = 0, stateNumOne = 0, stateNumTwo = 0;

    CLS;
    if(candidateOne[0] == '\0'){//error checking to make sure votes exist
        printf("No votes have been entered for Ivanka Trump, enter votes first.\n");
    }
    if(candidateTwo[0] == '\0'){//error checking to make sure votes exist
        printf("No votes have been entered for Michelle Obama, enter votes first.\n");
    }
    //Finds the Highest Number For Candidate One
    if(candidateOne[0] != '\0'){
        while(candidateOne[m] != '\0' && m < SIZE){//find out how big the array is at the moment
            m++;
        }
        for(i = 0; i < m ; i++){
            if(highestOne < candidateOne[i]){
                highestOne = candidateOne[i];
                stateNumOne = i;
            }
        }
        printf("Highest number of votes for Ivanka Trump is from State %i, with %i votes.\n", stateNumOne, highestOne);

        stateNumOne = 0;//Resets Variable to be reused

        //Finds the Lowest Number for Candidate One
        for(i = 0; i < m ; i++){
            if(lowestOne > candidateOne[i]){
                lowestOne = candidateOne[i];
                stateNumOne = i;
            }
        }
        printf("Lowest number of votes for Ivanka Trump is from State %i, with %i votes.\n", stateNumOne, lowestOne);
    }

    printf("\n");

    //Finds the Highest Number For Candidate Two
    if(candidateTwo[0] != '\0'){
        while(candidateTwo[n] != '\0' && n < SIZE){//find out how big the array is at the moment
            n++;
        }
        for(j = 0; j < n ; j++){
            if(highestTwo < candidateTwo[j]){ //goes through the array checking which value is bigger and switching accordingly
                highestTwo = candidateTwo[j];
                stateNumTwo = j; //keeps track of the state that was switched if any
            }
        }
        printf("highest number of votes for Michelle Obama is from State %i, with %i votes.\n", stateNumTwo, highestTwo);

        stateNumTwo = 0; //resets variable for resuse

        //Finds the Lowest Number For Candidate Two
        for(j = 0; j < n ; j++){
            if(lowestTwo > candidateTwo[j]){ //goes through the array checking which value is smaller and switching accordingly
                lowestTwo = candidateTwo[j];
                stateNumTwo = j; //keeps track of the state that was switched if any
            }
        }
        printf("Lowest number of votes for Michelle Obama is from State %i, with %i votes.\n", stateNumTwo, lowestTwo);
    }
    printf("\n");
}
//displays the votes accordingly
void displayVotes(int candidateOne[], int candidateTwo[]){
    int i = 0, j = 0;

    if(candidateOne[0] == '\0' && candidateTwo[0] == '\0'){ //checks to make sure votes are not empty
        printf("No votes have been entered yet, enter votes first");
    }else{
        CLS;
        printf("STATE\t TRUMP\t OBAMA\n"); //prints the header for the display
        while((i<SIZE && candidateOne[i] != '\0') || (i<SIZE && candidateTwo[i] != '\0')){ // runs the loop until it reaches the end of the array
            if(candidateOne[j] != '\0' || candidateTwo[j] != '\0'){
               printf("%i", j);
            }
            if(candidateOne[j] == 0){ //formats the result if space next to Ivank Trump is empty
               printf("\t");
            }
            if(candidateOne[j] != '\0' && j < SIZE){ // runs until the loop has reached the end of the array input
                printf("\t %i", candidateOne[j]); //prints out the result
            }
            if(candidateTwo[j] != '\0' && j < SIZE){
                printf("\t %i", candidateTwo[j]);
            }
            printf("\n");
            i++;
            j++;
        }
    }
    getchar();
}
//gets the votes from the user based on their selection and saves it to correct array
void getVotes(int candidate[]){
    int i=0;
    while(candidate[i] != '\0' && i < SIZE){ //searches for the next empty spot in the array
        i++;
    }
    if(i < SIZE){//verifies that the next available spot is not equal or greater than the max size
        printf("\nPlease enter votes for state %i: ", i);
        scanf("%i", &candidate[i]); FLUSH;
    }else{
        printf("\nERROR: All States votes for this candidate have already been submitted.\n");//Once the array is full, the user can no longer enter values
        getchar();
    }
}
//displays the main menu for the user
void mainMenu(){
    CLS;
    printf("***********************************************************\n");
    printf("**        CNN VOTER COLLECTION PROGRAM MAIN MENU         **\n");
    printf("***********************************************************\n");
    printf("1. Enter Votes from a state for Ivanka Trump\n");
    printf("2. Enter Votes from a state for Michelle Obama\n");
    printf("3. Display total votes for each candidate\n");
    printf("4. Display the all votes for a selected candidate in order\n");
    printf("5. List the state number(s) where Trump and Obama\n");
    printf("   received the exact same number of votes\n");
    printf("6. For each candidate display the highest number of votes\n");
    printf("   from any state, the lowest number of votes from any \n");
    printf("   state, & the average number of votes from all states.\n");
    printf("7. Election is over, Exit Program\n");
    printf("***********************************************************\n");
    printf("Enter your selection: ");
}

//clears the keyboard buffer.
void myFlush(){
	while(getchar() != '\n');
}

void sortVotes(int candidate[]){
    int tmp;//holds the value to be switched temporarily
    int i=0, j = 0, n = 0;
    while(candidate[n] != '\0' && n < SIZE){//find out how big the array is at the moment
        n++;
    }
    for (i = 0; i < n; i++){//loops x times until less than n (size of the filled array)
       for (j = 0; j < n - i - 1; j++){//loop that compares each value to the next except the last
            if (candidate[j] > candidate[j + 1] && candidate[j] > 0){//value, which will be the highest at the end of the first pass
               tmp = candidate[j]; //if values being compared are out of order, they are swapped using a temp variable
               candidate[j] = candidate[j + 1];
               candidate[j + 1] = tmp;
           }
       }
   }
}

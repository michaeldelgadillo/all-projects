/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 28 March 2019
Project Name: playingWithLetters
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//These are all the function prototypes to avoid errors in the code
//Which allows to be entered after "main"
void displayWord();
void displayWordBackVert();
void displayWordBackwards();
void displayWordVertically();
void getWord(char words[]);

int main(){

    char myWord[100];//initializes array variable of type char to store a word
    getWord(myWord);//This function calls and automatically returns the array results
    displayWord(myWord);//Displays word Normally
    displayWordBackwards(myWord);//Displays word in reverse
    displayWordVertically(myWord);//Displays the word vertically
    displayWordBackVert(myWord);//Displays the work upsidedown + vertically

    return 0;
}

//This function collects the user's information after prompt.
//Arrays are automatically returned
void getWord(char myWord[]){
    printf("Please enter a Word:");
    scanf("%s", myWord);
    system("cls");
    return;
}

//This function displays the word in simple form
void displayWord(char myWord[]){
    printf("The word is: %s\n", myWord);
    return;
}

//This function displays the word upside down and vertical
void displayWordBackVert(char myWord[]){
    int wordLength = strlen(myWord) - 1; //Counts the letters in the submitted word
    printf("The word upside down vertical is: \n");
    while(wordLength >= 0){ //uses the word length as a guide to perform the function using a while loop
        printf("%c\n", myWord[wordLength]);
        wordLength--;
    }
    printf("\n");
    return;
}

//This function displays the word in reverse
void displayWordBackwards(char myWord[]){
    int wordLength = strlen(myWord) - 1;
    printf("The word backwards is: ");
    while(wordLength >= 0){
        printf("%c", myWord[wordLength]);
        wordLength--;
    }
    printf("\n");
    return;
}

//This functions displays the word vertically
void displayWordVertically(char myWord[]){
    int wordLength = strlen(myWord) - 1;
    int i = 0;
    printf("The word vertical is:\n");
    while(wordLength >= i){
        printf("%c\n", myWord[i]);
        i++;
    }
    return;
}
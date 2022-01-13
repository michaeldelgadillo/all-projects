#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    /*This section contains all the inputs for the code below*/
    int inputValueOne, inputValueTwo;

    /*This section collects all of the required information from the user*/
    printf("Welcome! Please input two integer values.\n");
    printf("Value One:\n");
    scanf("%i", &inputValueOne);
    printf("Value Two:\n");
    scanf("%i", &inputValueTwo);

    /*This section performs addition, multiplication and division, then displays it to the user.*/
    printf("The sum of %i + %i = %i\n", inputValueOne, inputValueTwo, inputValueOne + inputValueTwo);
    printf("The product of %i * %i = %i\n", inputValueOne, inputValueTwo, inputValueOne * inputValueTwo);
    printf("The result of dividing %i / %i as an integer is %i\n", inputValueOne, inputValueTwo, inputValueOne / inputValueTwo);

    return 0;
}
/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 8 February 2019
Project Name: Shipping Assignment
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    /*This section contains all the inputs for the code below. Input must accept decimal places*/
    float packageWeight = 0.0;
    float shippingMiles = 0.0;
    float shippingCostByWeight = 0.0;
    float shippingCostByDistance = 0.0;
    char weightFormat[] = "pound";
    char mileFormat[] = "mile";


    /*This section prompts the user to enter the total number of miles the package will travel and weight of package*/
    printf("Welcome to the Shipping Calculator.\n");
    printf("Please enter the distance in miles the package will travel:\n");
    scanf("%f", &shippingMiles);
    printf("Please enter the weight of the package:\n");
    scanf("%f", &packageWeight);

    /*This Checks the weight input from the User using an if else statement & calculates costs*/
    if(packageWeight <= 13) {
        shippingCostByWeight = 13.13;
    }else{
        shippingCostByWeight = 13.13 + ((packageWeight - 13) * 1.55);
    }

    /*This Checks the Distance input from the User using an if else statement & calculates costs*/
    if(shippingMiles <= 321) {
        shippingCostByDistance = 3.21;
    }else{
        shippingCostByDistance = (ceil(shippingMiles / 321) * 3.21);
    }

    /*this checks the user's input and applies the appropriate formatting*/
    if(packageWeight > 1){
        strcpy(weightFormat, "LBS");
    }

    if(shippingMiles > 1){
        strcpy(mileFormat, "miles");
    }

    /*This prints the output after performing the necessary calculations*/
    printf("Package Weight...................:\t %.2f %s \n", packageWeight, weightFormat);
    printf("Distance to ship in Miles........:\t %.2f %s \n", shippingMiles, mileFormat);
    printf("Cost to ship based on weight is..:\t $%.2f \n", shippingCostByWeight);
    printf("Cost to ship based on distance is:\t $%.2f \n", shippingCostByDistance);
    printf("Total cost to ship is............:\t $%.2f \n", shippingCostByWeight + shippingCostByDistance);

    return 0;
}
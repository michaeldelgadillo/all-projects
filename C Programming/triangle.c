/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 21 Febuary 2019
Project Name: Triangle
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*One of the Variables used in the formula for creating
    the triangle.*/
    int rowTriangle, i, j;

    /*This section contains the message to collect and verify
    user's input is within 1-50.*/
    do
    {
      printf("Please enter a value from 1-50\n");
      scanf("%i", &rowTriangle);
    }
    while(rowTriangle < 1 || rowTriangle > 50);

    printf("\n");

    /*The first for loop is for the rows and the second one prints
    out the asterisks needed in that row. As "i" increments, so does the amount
    of times the second loop prints out n number of asterisks in relation to the
    value submitted by the user "rowTriangle".*/

    for(i = 0; i < rowTriangle; i++)
    {
        for(j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

   return 0;

}
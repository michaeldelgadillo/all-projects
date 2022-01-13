#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars = 0; //Allows the user the option to input the dollars using decimals
    int cents = 0, change = 0;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    cents = round(dollars * 100); //Converts the float dollars to a whole number to avoid rounding errors

    if (cents >= 25) // Checks the value of the users input against common coin sizes
    {
        change = cents / 25; // if the amount submitted 
        cents = cents % 25; //Simple math using modulo gives us the remainder and avoids the need for loops
    }
    if (cents >= 10)
    {
        change += cents / 10;
        cents = cents % 10;
    }
    if (cents >= 5)
    {
        change += cents / 5;
        cents = cents % 5;
    }
    if (cents >= 1)
    {
        change += cents / 1;
        cents = cents % 1;
    }

    printf("%i\n", change); //After the coins are counted, the final result is then displayed to the user.

}

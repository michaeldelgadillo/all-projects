#include <stdio.h>
#include <cs50.h>

int main()
{
    // The variables are initialized to avoid garbage values
    long creditCard = 0;
    int sum = 0, everyOtherDigit = 0, remainingDigits = 0, numberOfDigits = 0;

    do
    {
        creditCard = get_long("Number:");
    }
    while (creditCard < 1);

    //The variables below will be used to perform different calculations without affecting the main creditCard value
    long checkOne = creditCard / 10, checkTwo = creditCard, digits = creditCard, firstTwoDigits = creditCard;


    //Step One: every other digit is multiplied by two and then added together
    while (checkOne > 0)
    {
        //Any number larger than 9 is split into two components and then added together. I.E. if the current digit * 2 = 12,
        //then 12 becomes 1+2 before being added to the sum

        if ((checkOne % 10 * 2) > 9)
        {
            everyOtherDigit += (checkOne % 10 * 2 % 10) + (checkOne % 10 * 2 / 10);
        }
        else
        {
            everyOtherDigit += (checkOne % 10 * 2);
        }
        checkOne /= 100;
    }

    //Step two: Adds every other numbers starting from the last digit
    while (checkTwo > 0)
    {
        remainingDigits += checkTwo % 10;
        checkTwo /= 100;
    }

    //Combines the numbers in step one and step two
    sum = everyOtherDigit + remainingDigits;

    //Counts the number of digits in the CC number
    while (digits > 0)
    {

        digits /= 10;
        numberOfDigits++;
    }

    //Gets the first two digits of the CC Number
    while (firstTwoDigits > 100)
    {
        firstTwoDigits /= 10;
    }


    if (sum % 10 == 0) //(Checks if the last value of the sum is 0)
    {
        //Additional checks to verify the CC Number
        if (numberOfDigits == 13 && firstTwoDigits / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (numberOfDigits == 16 && firstTwoDigits / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (numberOfDigits == 16 && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if (numberOfDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

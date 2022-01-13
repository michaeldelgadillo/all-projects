#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check to see if user has submitted two variables at the command line
    if ((argc != 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check to see that each value in the 2nd commandline argument is a digit
    for (int i = 0, k = strlen(argv[1]); i < k; i++)
    {
        if (isalpha(argv[1][i]))
        {
             printf("Usage: ./caesar key\n");
             return 1;
        }
    }

    // Convert the string into an int
    int key = atoi(argv[1]);

    // Prompt user for the plaintext
   string text = get_string("plaintext: ");
    
    //Ciphertext Result
    printf("ciphertext: ");
    
    //Analyzes each character of the string.
    for (int i = 0, k = strlen(text); i < k; i++)
    {        
        if (isalpha(text[i])) //Checks to see if the character is a letter
        {
            if (isupper(text[i])) //Checks for case
            {
                //Handles wrap-around for capital letters
                printf("%c", ((text[i] - 65 + key) % 26) + 65);
            }
            else
            {
                //lowercase letters
                printf("%c", ((text[i] - 97 + key) % 26) + 97);
            }
        }
        else
        {
            //Prints any non alpha characters
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

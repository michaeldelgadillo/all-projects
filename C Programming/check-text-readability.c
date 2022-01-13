#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    // Get the input from the user to be processed
    string text = get_string("Text: "); 
   
    // L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float letterCounter = 0, wordCounter = 0, sentenceCounter = 0, L = 0, S = 0; 
    int index = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letterCounter++; //Counts each of the letters.
        }

        if (isspace(text[i]))
        {
            wordCounter++; //Counts each of the words by checking for spaces.
        }

        if ((text[i] == '.' || text[i] == '?' || text[i] == '!'))
        {
            sentenceCounter++;
        }
    }
    // Average number of letters per words. The variable wordCounter 
    // is incremented by 1 to account for the last word.
    L = letterCounter / (wordCounter + 1) * 100;
    
    // Average number of words per sentences.
    S = sentenceCounter / (wordCounter + 1) * 100; 
    
    // This is Coleman-Liau index formula used for determining the index value.
    index = round(0.0588 * L - 0.296 * S - 15.8); 

    // Determines the grade level based on the output value of the index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 12)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 12)
    {
        printf("Grade 16+\n");
    }
}  

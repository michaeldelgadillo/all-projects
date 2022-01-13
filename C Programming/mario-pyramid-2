#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height:"); //Gets the user's Input for height
    }
    while (height < 1 || height > 8); //Height Contraint


    for (int i = 0; i < height ; i++) //This is used for the Rows
    {
        for (int j = 0; j < height - i - 1; j++) //This section is for the spaces before the Hash
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) //This section is for the hash after the space
        {
            printf("#");
        }
        printf("  "); //Double Space in between the two sections of the pyramid
        
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n"); //This will create a new row after the formatting above is complete
    }
}

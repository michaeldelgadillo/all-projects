#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    //Ensure that the user entered 2 arguments at the command-line
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //open the 2 second argument entered at the command line and read it
    FILE *file = fopen(argv[1], "r");

    // Error Checking to make sure nothing went wrong
    if (file == NULL)
    {
        return 1;
    }

    unsigned char bytes[512];
    int jpeg_found = 0;
    int file_No = 0;
    char filename[15];

    sprintf(filename, "%03i.jpg", file_No);
    FILE *img = fopen(filename, "w");

    if (img == NULL)
    {
        return 1;
    }

    // fread(The array, The number of bytes to read, how many time to read the bytes, the file from which to read those bytes)
    while (fread(bytes, 1, 512, file))
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (jpeg_found == 0)
            {
                fwrite(bytes, 1, 512, img);
                jpeg_found = 1;
            }
            else
            {
                fclose(img);
                file_No++;
                sprintf(filename, "%03i.jpg", file_No);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    return 1;
                }
                fwrite(bytes, 1, 512, img);
            }

        }
        else if (jpeg_found == 1)
        {
            fwrite(bytes, 1, 512, img);
        }
    }

    fclose(img);
    fclose(file);
}

// Repeat until end of card
    // Read 512 bytes into a buffer
    // If start of a new JPEG
        // If first JPEG ...
            //write the first jpeg
        // Else ...
            //Close file and start a new one
        // Else if already found JPEG
            //Keep writing
    // End of Memory Card
    // Close all open files

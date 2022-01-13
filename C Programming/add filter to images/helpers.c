#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((float) ((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue)));
            int sepiaGreen = round((float) ((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue)));
            int sepiaBlue = round((float) ((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue)));

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*original)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j].rgbtRed = image[i][j].rgbtRed;
            original[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            int total_Red = 0;
            int total_Green = 0;
            int total_Blue = 0;
            int counter = 0; // Keeps track of each value added then used as a divisor for the average

            total_Red += original[i][j].rgbtRed;
            total_Green += original[i][j].rgbtGreen;
            total_Blue += original[i][j].rgbtBlue;
            counter++;


            if (j - 1 >= 0)// check Left
            {
                total_Red += original[i][j - 1].rgbtRed;
                total_Green += original[i][j - 1].rgbtGreen;
                total_Blue += original[i][j - 1].rgbtBlue;
                counter++;
            }


            if (i - 1 >= 0 && j - 1 >= 0 )// check Top-Left
            {
                total_Red += original[i - 1][j - 1].rgbtRed;
                total_Green += original[i - 1][j - 1].rgbtGreen;
                total_Blue += original[i - 1][j - 1].rgbtBlue;
                counter++;
            }


            if (i - 1 >= 0) // check Top
            {
               total_Red += original[i - 1][j].rgbtRed;
               total_Green += original[i - 1][j].rgbtGreen;
               total_Blue += original[i - 1][j].rgbtBlue;
               counter++;
            }

            if (i - 1 >= 0 && j < width - 1)// check Top-Right
            {
                total_Red += original[i - 1][j + 1].rgbtRed;
                total_Green += original[i - 1][j + 1].rgbtGreen;
                total_Blue += original[i - 1][j + 1].rgbtBlue;
                counter++;
            }

            if (j < width - 1)// check Right
            {
                total_Red += original[i][j + 1].rgbtRed;
                total_Green += original[i][j + 1].rgbtGreen;
                total_Blue += original[i][j + 1].rgbtBlue;
                counter++;
            }

            if (i < height - 1 && j < width - 1)// check Bottom-Right
            {
                total_Red += original[i + 1][j + 1].rgbtRed;
                total_Green += original[i + 1][j + 1].rgbtGreen;
                total_Blue += original[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            if (i < height - 1)// check Bottom
            {
               total_Red += original[i + 1][j].rgbtRed;
               total_Green += original[i + 1][j].rgbtGreen;
               total_Blue += original[i + 1][j].rgbtBlue;
               counter++;
            }

            if (i < height - 1 && j - 1 >= 0)// check Bottom-Left
            {
               total_Red += original[i + 1][j - 1].rgbtRed;
               total_Green += original[i + 1][j - 1].rgbtGreen;
               total_Blue += original[i + 1][j - 1].rgbtBlue;
               counter++;
            }

            image[i][j].rgbtRed = round((float)total_Red / counter);
            image[i][j].rgbtGreen = round((float)total_Green / counter);
            image[i][j].rgbtBlue = round((float)total_Blue / counter);
        }
    }

    return;
}

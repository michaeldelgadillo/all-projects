#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
  /*This section contains all the inputs for the code below*/
  float lithium;
  float osmium;
  float mercury;
  float krypton;
  float totalOunces;
  int containerSizeGallon;
  int containerSizeOunces;
  float step1, step2, step3, step4, step5;

  /*This section collects all of the required information from the user*/
  printf ("Welcome to Magic Formula: Please input values for each chemical, then press enter\n");
  printf ("Lithium:\n");
  scanf ("%f", &lithium);
  printf ("Osmium:\n");
  scanf ("%f", &osmium);
  printf ("Mercury:\n");
  scanf ("%f", &mercury);
  printf ("Krypton:\n");
  scanf ("%f", &krypton);

  /*This section performs the Magic Mixture as Specified by the client.*/
  step1 = (lithium + osmium);
  step2 = (step1 * lithium + osmium);
  step3 = (mercury * osmium + step2);
  step4 = (krypton * 1.5 + step3);
  step5 = (lithium * 2 + step4);

  /* This section converts the data from the previous section into appropriate measurements. 128 is the number of Ounces in a Gallon*/
  totalOunces = step5;
  containerSizeGallon = step5 / 128;
  containerSizeOunces = fmod(step5,128);

  /*This section displays the output after all the calculations have been performed.*/
  printf ("Lithium: %.2f oz.\n", lithium);
  printf ("Osmium: %.2f oz.\n", osmium);
  printf ("Mercury: %.2f oz.\n", mercury);
  printf ("Krypton: %.2f oz.\n", krypton);
  printf ("==================================================\n");
  printf ("Total Ounces you will need: %.2f\n", totalOunces);
  printf ("==================================================\n");
  printf ("You will need a container that holds %i gallons and %i ounces.\n", containerSizeGallon, containerSizeOunces);

  return 0;
}

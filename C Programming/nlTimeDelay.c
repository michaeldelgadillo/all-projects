/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>

void delay(int milliseconds);

int main()
{
    printf("Hello World\n");
    delay(1000);
    printf("Hello World\n");
    delay(1000);
    printf("Hello World\n");
    delay(1000);
    printf("Hello World\n");

    printf("\033[1;11H");
    printf("New Line One\n");
    delay(1000);
    printf("\033[2;11H");
    printf("New Line two\n");
    delay(1000);
    printf("\033[3;11H");
    printf("New Line three\n");
    delay(1000);
    printf("\033[4;1H");
    printf("New Line Four\n");

    return 0;
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
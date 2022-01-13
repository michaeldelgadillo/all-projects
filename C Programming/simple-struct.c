#include <stdio.h>
#include <cs50.h>
#include <string.h>


typedef struct
{
    string name;
    string number;
    int id;
    string lastName;
}
person; // The name of the struct

int main(void)
{

    person people[4]; // Declare a variable using the newly created struct. It's like saying int or float, etc.

    people[0].name = "emma";
    people[0].number = "4075555090";
    people[0].id = 313154;
    people[0].lastName = "Roberts";

    people[1].name = "Mike";
    people[1].number = "4075555151";
    people[1].id = 999554;
    people[1].lastName = "Jones";


    for (int i = 0; i < 4; i++)
    {
        if(strcmp(people[i].name, "Mike") == 0) // If this statement is true, it will equal 0
        {
            printf("%s\n", people[i].name);
            printf("%s\n", people[i].number);
            printf("%i\n", people[i].id);
            printf("%s\n", people[i].lastName);

            return 0;
        }
    }
    printf("Not Found\n");
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int s;
    do
    {
        s = get_int("Start size: ");
    }
    while (s < 9);

    //Prompt for end size
    int f;
    do
    {
        f = get_int("End size: ");
    }
    while (f < s);

    //Calculate number of years until we reach threshold
    int years = 0;
    while (s < f)
    {
        s = s + s / 3 - s / 4;
        years++;
    }


    //Print number of years
    printf("Start size: %i\n", s);
    printf("End size: %i\n", f);
    printf("Years: %i\n", years);
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a, b = 0;

    //Get input from user
    do
    {
        a = get_int("Height: ");
    }
    while (a < 1 || a > 8);

    //Printing out rows
    for (int i = a; i >= 1; i--)
    {
        //Printing out coloms
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= b; k++)
        {
            printf("#");
        }
        b++;
        printf("\n");

    }

}
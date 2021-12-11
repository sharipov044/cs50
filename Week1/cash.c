#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Set variables
    int quaters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    float dollars;
    
    //To get input from user
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    //To convert value into inteder
    int cents = round(dollars * 100);
    
    printf("%i\n", cents);
    
    //To get coins by its values
    while (cents >= 25)
    {
        cents = cents - 25;
        quaters++;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    //To calculate total number of coins
    int total = quaters + dimes + nickels + pennies;
    //To print coins
    printf("Total number of coins: %i\n", total);
    printf("Quaters: %i\n", quaters);
    printf("Dimes: %i\n", dimes);
    printf("Nickels: %i\n", nickels);
    printf("Pennies: %i\n", pennies);
}
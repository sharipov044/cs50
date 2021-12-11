#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get credit number
    long num = get_long("Enter credit card number: ");

    //Count length
    int length = 0;
    long i = num;
    while (i > 0)
    {
        i = i / 10;
        length++;
    }

    //Check if length is valid
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long j = num;
    int total = 0;
    int mod1, mod2;
    int d1, d2;

    do
    {
        //Remove last digit and add to sum1
        mod1 = j % 10;
        j = j / 10;
        sum1 = sum1 + mod1;

        //Remove second last digit
        mod2 = j % 10;
        j = j / 10;

        //Multiply second last gidit by 2 and add them to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (j > 0);

    total = sum1 + sum2;

    //Check algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Get starting digits
    long start = num;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // Check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }

    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
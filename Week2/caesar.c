#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("NULL\n");
        return 1;
    }

    const int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("NULL\n");
        return 0;
    }
    else
    {
        string code = get_string("Plaintext: ");
        printf("Ciphertext: ");
        for (int i = 0; i < strlen(code); i++)
        {
            if isupper(code[i])
            {
                printf("%c", 'A' + (code[i] - 'A' + k) % 26);
            }
            else if islower(code[i])
            {
                printf("%c", 'a' + (code[i] - 'a' + k) % 26);
            }
            else
            {
                printf("%c", code[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
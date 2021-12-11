#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkKey(); //for validate key
void Do_substitute(); //for further substitute
void alpha_arr_val(char, string); //to get for alphabet array value of each plain text element

int main(int argc, string argv[])
{
    if (argc == 2) //number of commands in terminal
    {
        if (strlen(argv[1])== 26)
        {
            for (int i = 0; i < strlen(argv[1]); i++) //checking each element of string
            {
                if (!isalpha(argv[1][i])) //if contain non-alphabet
                {
                    printf("Key must contain 26 letters!\n");
                    return 1;
                }
                for (int j = i + 1; j < strlen(argv[1]); j++) //checking to the next element of argv
                {
                    if (toupper(argv[1][j]) == toupper(argv[1][i])) //checking repeated elements
                    {
                        printf("Key must not contain repeated letters!\n");
                        return 1;
                    }
                }
            }

            Do_substitute(argv[1]);
        }

        else
        {
            printf("Key must contain 26 letters!\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

void Do_substitute(string key)
{
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i])) //check if letter alphabet
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alpha_arr_val(tolower(x), key);
            }
            else
            {
                alpha_arr_val(toupper(x), key);
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}

void alpha_arr_val(char pos, string key)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < strlen(alpha); i++)
    {
        if (islower(pos)) // p[i] is lower
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else // for UPPERCASE // p[i] is upper
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}
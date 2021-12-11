#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;

    //Funtion to coount letters, words and sentences
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterCount++;
        }
        else if (text[i] == ' ')
        {
            wordCount++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentenceCount++;
        }
    }



    //To calculate grade
    float grade = (0.0588 * (100 * (float) letterCount / (float) wordCount)) - (0.296 * (100 * (float) sentenceCount / (float) wordCount)) - 15.8;

    //To print out results
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
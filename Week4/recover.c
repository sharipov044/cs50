#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <getopt.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./revocer image\n");
        return 1;
    }
    else
    {
        //open Card.raw
        char *input_file_name = argv[1];
        FILE *input_pointer = fopen(input_file_name, "r");
        if (input_pointer == NULL)
        {
            printf("Error: cannot open %s file\n", input_file_name);
            return 2;
        }
        //initialize variables
        BYTE buffer[512];
        int count = 0;
        FILE *image_pointer = NULL;
        char filename[8];

        //Repeat untill end of the card
        while (fread(&buffer, 512, 1, input_pointer) == 1)
        {
            //if start of a new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                //if not first jpeg close previous
                if (!(count == 0))
                {
                    fclose(image_pointer);
                }
                //initialize file
                sprintf(filename, "%03i.jpg", count);
                image_pointer = fopen(filename, "w");
                count++;
            }
            //if jpeg has been found write it to the file
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, image_pointer);
            }
        }
        fclose(input_pointer);
        fclose(image_pointer);

        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512 //Digital cameras often initialize cards with a FAT file system whose “block size” is 512 bytes
#define FILE_NAME_SIZE 8 //Define the size of the File Name for each JPEG file
typedef uint8_t BYTE;

bool StarNewJPEG(BYTE buffer[]);

int main(int argc, char *argv[])
{
//Check for exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return (1);
    }

//Open file set on argument
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("File not found\n");
        return (1);
    }

    BYTE buffer [BLOCK_SIZE]; //Need a buffer to read 1 block of information at the same time
    int imageCount = 0;
    bool FirstJPEG = false;
    FILE *outfile;

    while (fread(buffer, BLOCK_SIZE, 1, file)) //Reading 1 Block of the "file" into the buffer
    {
        if (StarNewJPEG(buffer)) //Check if the block contains a JPEG file
        {
            if (!FirstJPEG)
            {
                FirstJPEG = true;
            }
            else
            {
                fclose(outfile);
            }

            char FileName[FILE_NAME_SIZE];
            sprintf(FileName, "%03i.jpg", imageCount++); //Set the name fo each JPEG image
            outfile = fopen(FileName, "w");

            if (outfile == NULL) //In case there is an issue with the output file
            {
                return 1;
            }

            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (FirstJPEG) //If we havent finish with the file, we have to keep writing onto the existing one
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }

    fclose(file);
    fclose(outfile);
}




bool StarNewJPEG(BYTE buffer[])
{
//Check if the three first bytes belongs to a JPEGs image
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}
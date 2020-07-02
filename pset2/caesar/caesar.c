#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        const int key = atoi(argv[1]);
        int len = strlen(argv[1]);
        bool isKeyValid = true;

        for (int i = 0; i < len; i++) //Checking if any of the characters of the command-line argument is not a decimal digit
        {
            if (isdigit(argv[1][i]) == false) 
            {
                isKeyValid = false;
                i = len;
            }
        }
        
        if (isKeyValid)
        {
            string text = get_string("plaintext: ");
            int lenght = strlen(text);
            for (int i = 0; i <= lenght; i++)
            {
                if (text[i] >= 'A' && text[i] <= 'Z') //It's an Upper Case
                {
                    text[i] = ((((text[i] - 'A') + key) % 26) + 'A');
                }
                else if (text[i] >= 'a' && text[i] <= 'z') //It's a Lower Case
                {
                    text[i] = ((((text[i] - 'a') + key) % 26) + 'a');
                }
                else
                {
                    text[i] = text[i];// If it's not a letter
                }
            }
            printf("ciphertext: %s\n", text);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
    }
    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
}
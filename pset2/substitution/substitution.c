#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
//Key validation process   
    const string key = argv[1];
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) == 26)
    {
        for (int i = 0; i <= strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
        int matches = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    matches++;
                    break;
                }
            }
        }
        if (matches != 26)
        {
            printf("Key must not contain duplicate characters.\n");
            return 1;
        }
    }
//If the Key is valid, then run the rest of the code    
    string text = get_string("plaintext: ");
    int lenght = strlen(text);
    char ciphertext[lenght];
    string abc = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i <= lenght; i++)
    {
        if (isupper(text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (abc[j] == tolower(text[i]))
                {
                    ciphertext[i] = toupper(key[j]);
                    break;
                }
            }
        }
        else if (islower(text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (abc[j] == text[i])
                {
                    ciphertext[i] = tolower(key[j]);
                    break;
                }
            }
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
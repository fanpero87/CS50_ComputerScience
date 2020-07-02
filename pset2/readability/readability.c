#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int average_number_letters(string);
int average_number_words(string);
int average_number_sentences(string);

int main(void)
{
    string text = get_string("Text: ");

    float l = average_number_letters(text);
    float w = average_number_words(text);
    float s = average_number_sentences(text);
//........................................
//Calculate the Coleman-Liau index of a text
//........................................
    float average_letters = (l / w) * 100;
    float average_sentences = (s / w) * 100;
    int index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index > 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
//........................................
//Function that counts the number of letters that show up in the text
//........................................
int average_number_letters(string text)
{
    int lenght = strlen(text);
    int count = 0;
    for (int i = 0; i <= lenght; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count += 1;
        }
    }
    return count;
}
//........................................
//Function that counts the number of words that show up in the text
//........................................
int average_number_words(string text)
{
    int lenght = strlen(text);
    int count = 0;
    for (int i = 0; i <= lenght; i++)
    {
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    return count + 1;
}
//........................................
//Function that counts the number of senences that show up in the text
//........................................
int average_number_sentences(string text)
{
    int lenght = strlen(text);
    int count = 0;
    for (int i = 0; i <= lenght; i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count += 1;
        }
    }
    return count;
}
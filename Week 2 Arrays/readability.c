#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// prototypes for all of the functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau_index(string text);


int main(void)
{
    // get input text
    string text = get_string("Text: ");
    int gradeLevel = coleman_liau_index(text);
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}


// function that counts the letters
int count_letters(string text)
{
    int length = strlen(text);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// function that counts the words
int count_words(string text)
{
    int length = strlen(text);
    // start count at one since there will be one less space than word ("hi there" is two words with one space)
    int count = 1;
    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// function that counts the sentences (punctuation .!?)
int count_sentences(string text)
{
    int length = strlen(text);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

int coleman_liau_index(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // this uses (float) or else it does the division as an integer and not a float.
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("Letters: %i\tWords: %i\tSentences: %i\tL: %f\tS: %f\tIndex: %i\n", letters, words, sentences, L, S, index);
    return index;
}

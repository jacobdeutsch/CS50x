#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char plainLetter, string key);

int main(int argc, string argv[])
{
    //check that there is one a single argument passed to the program, if not return 1
    if (argc != 2)
    {
        printf("Error: You must pass a single argument as the key.\n");
        return 1;
    }

    // read key
    string key = argv[1];

    // convert key to uppercase for ease of processing
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    // check for 26 characters
    if (strlen(key) != 26)
    {
        printf("Error: Your key must be 26 characters long.\n");
        return 1;
    }

    // check for alpha only characters
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Error: Your key must be alphabetic characters only.\n");
            return 1;
        }
    }

    // check for each character being used only once.
    string alphabet[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < 26; i++)
    {
        if (strstr(key, alphabet[i]) == NULL)
        {
            printf("Error: Your key must use each letter only once.\n");
            return 1;
        }
    }

    // get the plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    int textLength = strlen(plaintext);
    // loop through each plaintext character
    for (int i = 0; i < textLength; i++)
    {
        encrypt(plaintext[i], key);
    }
    printf("\n");
    return 0;
}


void encrypt(char plainLetter, string key)
{
    // if not alpha, just print character
    if (!isalpha(plainLetter))
    {
        printf("%c", plainLetter);
    }

    // do encryption
    else if (isupper(plainLetter))
    {
        plainLetter -= 65;
        int x = plainLetter;
        printf("%c", key[x]);
    }
    else
    {
        plainLetter -= 97;
        int x = plainLetter;
        printf("%c", tolower(key[x]));
    }

}

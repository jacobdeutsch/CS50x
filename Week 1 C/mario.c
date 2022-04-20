#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for size of block pyramid and reprompt until it is between 1 and 8
    int size = -1;
    while (size < 1 || size > 8)
    {
        size = get_int("What size block pyramid?\t");
    }
    // create variables for whitespace and octothorpes and instantiate them with the initial sizes
    int whitespace = size - 1;
    int octothorpe = 1;

    // main loop to run the program through octothorpe = size (which will stop printing after a size number of octothorpes)
    while (octothorpe <= size)
    {
        // print leading whitespace
        for (int i = 0; i < whitespace; i++)
        {
            printf(" ");
        }
        //print first set of octothorpes
        for (int i = 0; i < octothorpe; i++)
        {
            printf("#");
        }
        // print the two blank spaces
        printf("  ");
        //print second set of octothorpes
        for (int i = 0; i < octothorpe; i++)
        {
            printf("#");
        }
        //print new line
        printf("\n");
        //increment octothorpe and decrement whitespace
        octothorpe++;
        whitespace--;
    }
}

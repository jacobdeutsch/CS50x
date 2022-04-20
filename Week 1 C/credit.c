#include <cs50.h>
#include <stdio.h>

long removeLastDigit(long number);
int multiplied(long cardNum);
int added(long cardNum);
bool isVisa(long cardNum);
bool isAmex(long cardNum);
bool isMasterCard(long cardNum);


int main(void)
{
    // Prompt for card number
    long input = get_long("What is your credit card number?\t");
    int luhnOutput = multiplied(input) + added(input);
    // if the last number isn't 0, it's invalid
    if (luhnOutput % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (isVisa(input))
    {
        printf("VISA\n");
    }
    else if (isAmex(input))
    {
        printf("AMEX\n");
    }
    else if (isMasterCard(input))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

long removeLastDigit(long number)
{
    //remove last digit (set last digit to 0 and then divide by 10)
    number = (number - (number % 10)) / 10;
    return number;
}

// multiplied will return the value of the numbers that are multiplied by 2 and then added together
int multiplied(long cardNum)
{
    // instiatate variable for return value
    int sum = 0;
    //remove last digit
    cardNum = removeLastDigit(cardNum);
    while (cardNum > 0)
    {
        // double last digit in number
        int digitMath = (cardNum % 10) * 2;
        if (digitMath < 10)
        {
            sum += digitMath;
        }
        else
        {
            sum += 1 + (digitMath % 10);
        }

        // move 2 spaces over in card number
        cardNum = removeLastDigit(cardNum);
        cardNum = removeLastDigit(cardNum);
    }
    return sum;
}

int added(long cardNum)
{
    // instiatate variable for return value
    int sum = 0;
    while (cardNum > 0)
    {
        // add last digit in number
        sum += (cardNum % 10);

        // move 2 spaces over in card number
        cardNum = removeLastDigit(cardNum);
        cardNum = removeLastDigit(cardNum);
    }
    return sum;
}

int length(long cardNum)
{
    int counter = 0;
    while (cardNum > 0)
    {
        counter++;
        cardNum = cardNum / 10;
    }
    return counter;
}

// returns the leading one digit of the card number
int leadingOneDigit(long cardNum)
{
    while (true)
    {
        if (cardNum > 0 && cardNum < 10)
        {
            return cardNum;
        }
        cardNum = cardNum / 10;
    }
}

// returns the leading two digits of the card number
int leadingTwoDigits(long cardNum)
{
    while (true)
    {
        if (cardNum > 9 && cardNum < 100)
        {
            return cardNum;
        }
        cardNum = cardNum / 10;
    }
}

bool isVisa(long cardNum)
{
    // start with lengths
    if (length(cardNum) == 13 || length(cardNum) == 16)
    {
        if (leadingOneDigit(cardNum) == 4)
        {
            return true;
        }
    }
    return false;
}

bool isMasterCard(long cardNum)
{
    // start with lengths
    if (length(cardNum) == 16)
    {
        if (leadingTwoDigits(cardNum) >= 51 && leadingTwoDigits(cardNum) <= 55)
        {
            return true;
        }
    }
    return false;
}

bool isAmex(long cardNum)
{
    // start with lengths
    if (length(cardNum) == 15)
    {
        if (leadingTwoDigits(cardNum) == 34 || leadingTwoDigits(cardNum) == 37)
        {
            return true;
        }
    }
    return false;
}

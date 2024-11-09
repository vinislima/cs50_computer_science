
#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int ft_sum_digit(long card_number);
int ft_mult_digit(int last_digit);
bool valid_amex(long card_number, int count_digit);
bool valid_master(long card_number, int count_digit);
bool valid_visa(long card_number, int count_digit);

bool valid_amex(long card_number, int count_digit)
{
    int first_two_digit = card_number / pow(10, 13);
    if ((count_digit == 15) && (first_two_digit == 34 || first_two_digit == 37))
        return (true);
    else
        return (false);
}

bool valid_master(long card_number, int count_digit)
{
    int first_two_digit = card_number / pow(10, 14);
    if ((count_digit == 16) && (first_two_digit > 50 && first_two_digit < 56))
        return (true);
    else
        return (false);
}

bool valid_visa(long card_number, int count_digit)
{
    if (count_digit == 13)
    {
        int first_digit = card_number / pow(10, 12);
        if (first_digit == 4)
            return (true);
    }
    else if (count_digit == 16)
    {
        int first_digit = card_number / pow(10, 15);
        if (first_digit == 4)
            return (true);
    }
    return (false);
}

int ft_mult_digit(int last_digit)
{
    int mult = last_digit * 2;
    int sum = 0;
    while (mult > 0)
    {
        int last_mult = mult % 10;
        sum = sum + last_mult;
        mult = mult / 10;
    }
    return (sum);
}

int ft_sum_digit(long card_number)
{
    int sum = 0;
    bool alt_number = false;
    while (card_number > 0)
    {
        if (alt_number == true)
        {
            int last_digit = card_number % 10;
            int product = ft_mult_digit(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = card_number % 10;
            sum = sum + last_digit;
        }
        alt_number = !alt_number;
        card_number = card_number / 10;
    }
    sum = sum % 10;
    return (sum);
}

int main(void)
{
    long card_number;
    long count_digit;
    int size;
    int count;

    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    count = 0;
    count_digit = card_number;
    while (count_digit != 0)
    {
        count_digit = count_digit / 10;
        count++;
    }

    int sum_digit = ft_sum_digit(card_number);
    bool amex = valid_amex(card_number, count);
    bool master = valid_master(card_number, count);
    bool visa = valid_visa(card_number, count);
    if (sum_digit != 0 || count < 13)
    {
        printf("INVALID\n");
        return (0);
    }
    else if (amex == true)
        printf("AMEX\n");
    else if (master == true)
        printf("MASTERCARD\n");
    else if (visa == true)
        printf("VISA\n");
    else
        printf("INVALID\n");
    return (0);
}

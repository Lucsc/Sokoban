/*
** EPITECH PROJECT, 2020
** my_put_unsigned_decimal.c
** File description:
** unsigned_decimal
*/

#include "my.h"

int my_put_unsigned_decimal(unsigned int nbr)
{
    unsigned int res;

    if (nbr >= 10) {
        res = nbr % 10;
        nbr = nbr / 10;
        my_put_unsigned_decimal(nbr);
    } else if (nbr > 0) {
        res = nbr % 10;
        nbr = nbr / 10;
    }
    my_putchar(res + '0');
}

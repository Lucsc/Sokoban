/*
** EPITECH PROJECT, 2020
** my_put_hexadecimal.c
** File description:
** hexadecimal
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int my_put_hexadecimal_x(int nbr)
{
    int res;

    if (nbr == 0) {
        my_putchar(0 + '0');
        return (0);
    }
    if (nbr >= 16) {
        res = nbr % 16;
        nbr = nbr / 16;
        my_put_unsigned_decimal(nbr);
    } else if (nbr > 0) {
        res = nbr % 16;
        nbr = nbr / 16;
    }
    if (res >= 10)
        my_putchar(res + '0' + 39);
    else
        my_putchar(res + '0');
}

int my_put_hexadecimal_xcaps(int nbr)
{
    int res;

    if (nbr == 0) {
        my_putchar('0' + 0);
        return (0);
    }
    if (nbr >= 16) {
        res = nbr % 16;
        nbr = nbr / 16;
        my_put_hexadecimal_xcaps(nbr);
    } else if (nbr > 0) {
        res = nbr % 16;
        nbr = nbr / 16;
    }
    if (res >= 10)
        my_putchar(res + '0' + 7);
    else
        my_putchar(res + '0');
}

int my_put_hexadecimal_p(int nbr)
{
    int res;

    if (nbr == 0) {
        my_putstr("(nil)");
        return (84);
    }
    my_putstr("0x");
    if (nbr >= 16) {
        res = nbr % 16;
        nbr = nbr / 16;
        my_put_hexadecimal_xcaps(nbr);
    } else if (nbr > 0) {
        res = nbr % 16;
        nbr = nbr / 16;
    }
    if (res >= 10)
        my_putchar(res + '0' + 39);
    else
        my_putchar(res + '0');
}

/*
** EPITECH PROJECT, 2020
** my_put_octal.c
** File description:
** convert binary in octal
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_put_octal(unsigned int nbr)
{
    unsigned int rest;

    if (nbr == 0) {
        my_putchar(0 + '0');
        return (0);
    }
    if (nbr >= 8) {
        rest = nbr % 8;
        nbr = nbr / 8;
        my_put_octal(nbr);
    } else if (nbr > 0) {
        rest = nbr % 8;
        nbr = nbr / 8;
    }
    my_putchar(rest + '0');
}

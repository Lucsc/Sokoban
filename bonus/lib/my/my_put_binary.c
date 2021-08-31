/*
** EPITECH PROJECT, 2020
** my_put_binary.c
** File description:
** convert nbr in binary
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_put_binary(unsigned int nbr)
{
    unsigned int res;

    if (nbr == 0) {
        my_putchar(0 + '0');
        return (0);
    }
    if (nbr >= 2) {
        res = nbr % 2;
        nbr = nbr / 2;
        my_put_binary(nbr);
    } else if (nbr > 0) {
        res = nbr % 2;
        nbr = nbr / 2;
    }
    my_putchar(res + '0');
}

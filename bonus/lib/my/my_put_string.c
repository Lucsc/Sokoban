/*
** EPITECH PROJECT, 2020
** my_put_string
** File description:
** S
*/

#include "my.h"

int addzero(int nb)
{
    int res;
    int tab[3] = {0, 0, 0};

    for (int end = 2; end >= 0; end--) {
        res = nb % 8;
        nb = nb / 8;
        tab[end] = res;
    }
    for (int beg = 0; beg != 3; beg++)
        my_put_nbr(tab[beg]);
}

void my_put_string(char *nb)
{
    int r = 0;

    while (nb[r] != '\0') {
        if (nb[r] < 32 || nb[r] >= 127) {
            my_putchar('\\');
            addzero(nb[r]);
        } else
            my_putchar(nb[r]);
        r++;
    }
}
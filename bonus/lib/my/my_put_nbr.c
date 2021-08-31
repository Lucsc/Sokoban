/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int n;

    n = nb;
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10)
        my_put_nbr(n / 10);
        my_putchar(n % 10 + '0');
}
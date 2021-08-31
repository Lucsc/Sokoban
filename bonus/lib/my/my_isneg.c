/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** my_isneg.c
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{

    if (n >= 0)
        my_putchar('P');
    else if (n < 0)
        my_putchar('N');
    return (0);
}

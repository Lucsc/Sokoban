/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

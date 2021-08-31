/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr.c
*/
#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int k = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            k *= -1;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb + str[i] - 48;
            nb = nb * 10;
        } else if (str[i] != '-' && str[i] != '+' && nb != 0) {
            break;
        }
        i++;
    }
    nb /= 10;
    nb *= k;
    return (nb);
}

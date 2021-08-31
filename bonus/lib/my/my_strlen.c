/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0') {
        nbr++;
    }
    return (nbr);
}

/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** my_strncat.c
*/
#include <unistd.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int tmp = my_strlen(dest);

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[i + tmp] = src[i];
    dest[i + tmp] = '\0';
    return (dest);
}

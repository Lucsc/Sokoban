/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

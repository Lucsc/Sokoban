/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat.c
*/
#include <unistd.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int tmp = my_strlen(dest);

    while (src[i] != '\0'){
        dest[tmp + i] = src[i];
        i++;
        dest[tmp + i] = '\0';
    }
    return (dest);
}

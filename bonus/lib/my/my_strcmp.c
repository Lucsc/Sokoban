/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp.c
*/
#include <stdio.h>
#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

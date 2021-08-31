/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include <stdio.h>

void afterflag(char *s, int i)
{
    while (s[i] != '\0') {
        if (s[i] == '%')
            break;
        my_putchar(s[i]);
        i++;
    }
}

int check_space_ifsharp(char *s, int r)
{
    while (s[r] == ' ')
        r++;
    return (r);
}

int check_space_sharp(char *s, int i)
{
    for (int r = i; s[r] == ' ' || s[r] == '#'; r++) {
        if (s[r] == '#' && s[r + 1] != ' ') {
            r++;
            return (r);
        }
        if (s[r] == '#' && s[r + 1] == ' ') {
            r++;
            r = check_space_ifsharp(s, r);
            return (r);
        }
    }

    while (s[i] == ' ' ) {
        i++;
        if (s[i] != ' ') {
            my_putchar(' ');
            break;
        }
    }
    return (i);
}

int beforepourcent(char *s)
{
    int i = 0;

    while (s[i] != '%') {
        my_putchar(s[i]);
        i++;
        if (s[i] == '\0')
            break;
    }
    i++;
    return (i);
}

void my_printf(char *s, ...)
{
    va_list para;
    int v;

    va_start(para, s);
    for (int i = beforepourcent(s); s[i] != '\0'; i++) {
        if (s[i - 1] == '%') {
            v = i;
            i = check_space_sharp(s, i);
            if (s[i] == 'c' || s[i] == 'i' || s[i] == 'd' || s[i] == 'o')
                my_switchint(s, s[i], v, va_arg(para, int));
            if (s[i] == 'b' || s[i] == 'p' || s[i] == 'x' || s[i] == 'X')
                my_switchint(s, s[i], v, va_arg(para, int));
            if (s[i] == 's' || s[i] == 'S')
                my_switchchar(s[i], va_arg(para, char *));
            if (s[i] == 'u' || s[i] == '%')
                my_switch_unsignedint(s[i], va_arg(para, unsigned int));
            i++;
            afterflag(s, i);
        }
    }
    va_end(para);
}
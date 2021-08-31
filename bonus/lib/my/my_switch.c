/*
** EPITECH PROJECT, 2020
** my_switch.c
** File description:
** switch int/char * /unsigned int
*/

#include "my.h"

void ifsharp(char *j, char s, int v)
{
    while (j[v] == ' ' && j[v] != s || j[v] == '#' && j[v] != s) {
        if (j[v] == '#' ) {
            switch (s) {
            case 'o' : my_putchar(0 + '0'); break;
            case 'x' : my_putstr("0x"); break;
            case 'X' : my_putstr("0X"); break;
            }
        }
        v++;
    }
    return;
}

void my_switch_unsignedint(char s, unsigned int r)
{
    switch (s) {
    case 'u' : my_put_unsigned_decimal(r); break;
    case '%' : my_putchar('%'); break;
    }
    return;
}

void my_switchint(char *j, char s, int v, int r)
{
    ifsharp(j, s, v);
    switch (s) {
    case 'o' : my_put_octal(r); break;
    case 'c' : my_putchar(r); break;
    case 'i' : case 'd' : my_put_nbr(r); break;
    case 'x' : my_put_hexadecimal_x(r); break;
    case 'X' : my_put_hexadecimal_xcaps(r); break;
    case 'p' : my_put_hexadecimal_p(r); break;
    case 'b' : my_put_binary(r); break;
    }
    return;
}

void my_switchchar(char s, char *r)
{
    switch (s) {
    case 's' : my_putstr(r); return;
    case 'S' : my_put_string(r); break;
    }
    return;
}
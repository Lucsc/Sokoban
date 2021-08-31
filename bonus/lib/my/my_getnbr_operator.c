/*
** EPITECH PROJECT, 2020
** getnbrop
** File description:
** getnbrop
*/

int my_getnbr_operator(char str)
{
    int a = 0;

    if (str == '-')
        a = 1;
    if (str == '+')
        a = 2;
    if (str == '*')
        a = 3;
    if (str == '/')
        a = 4;
    if (str == '%')
        a = 5;
    return a;
}

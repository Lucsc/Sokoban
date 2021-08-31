/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** getscore
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <term.h>
#include <ncurses.h>
#include "sokoban.h"

int getthefifth(int first, char *buffer)
{
    int r = 0;
    int k = 0;

    for (; k < 6; r++)
        if (buffer[r] == '\n')
            k++;
    r -= 3;
    if (buffer[r] == '0')
        return (first = buffer[r+1] - '0');
    else
        return (first = ((buffer[r] - '0') * 10 + buffer[r+1]) - '0');
}

int getthefourth(int first, char *buffer)
{
    int r = 0;
    int k = 0;

    for (; k < 5; r++)
        if (buffer[r] == '\n')
            k++;
    r -= 3;
    if (buffer[r] == '0')
        return (first = buffer[r+1] - '0');
    else
        return (first = ((buffer[r] - '0') * 10 + buffer[r+1]) - '0');
}

int getthethird(int first, char *buffer)
{
    int r = 0;
    int k = 0;

    for (; k < 4; r++)
        if (buffer[r] == '\n')
            k++;
    r -= 3;
    if (buffer[r] == '0')
        return (first = buffer[r+1] - '0');
    else
        return (first = ((buffer[r] - '0') * 10 + buffer[r+1]) - '0');
}

int getthesecond(int first, char *buffer)
{
    int r = 0;
    int k = 0;

    for (; k < 3; r++)
        if (buffer[r] == '\n')
            k++;
    r -= 3;
    if (buffer[r] == '0')
        return (first = buffer[r+1] - '0');
    else
        return (first = ((buffer[r] - '0') * 10 + buffer[r+1]) - '0');
}

int getthefirst(int first, char *buffer)
{
    int r = 0;
    int k = 0;

    for (; k < 2; r++)
        if (buffer[r] == '\n')
            k++;
    r -= 3;
    if (buffer[r] == '0')
        return (first = buffer[r+1] - '0');
    else
        return (first = ((buffer[r] - '0') * 10 + buffer[r+1]) - '0');
}
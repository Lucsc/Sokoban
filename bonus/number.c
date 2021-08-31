/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** number
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ncurses.h>
#include "sokoban.h"
#include <signal.h>
#include <time.h>
#include <stdio.h>

void zero(void)
{
    char *one[] = { ".o00o.",
                "0    o",
                "o    0",
                "o    o",
                "0    0",
                "o    0",
                "`0oo0'"};
    int fd = 0;

    clear();
    for (int i = 0, y = 0; i < 7; i++, y++) {
        fd = my_strlen(one[i]);
        mvwprintw(stdscr, LINES/2 + y, COLS/2 -  fd / 2, one[i]);
    }
    refresh();
    sleep(1);
}

void two(void)
{
    char *one[] = { ".o00o.",
                "     0",
                "     o",
                "    0'",
                "   0  ",
                " .0   ",
                "o0o0o0"};
    int fd = 0;

    clear();
    for (int i = 0, y = 0; i < 7; i++, y++) {
        fd = my_strlen(one[i]);
        mvwprintw(stdscr, LINES/2 + y, COLS/2 -  fd / 2, one[i]);
    }
    refresh();
    sleep(1);
}

void three(void)
{
    char *one[] = {".o00o.",
                "     0",
                "     o",
                "  .o0 ",
                "     o",
                "     0",
                "`0oo0'"};
    int fd = 0;

    clear();
    for (int i = 0, y = 0; i < 7; i++, y++) {
        fd = my_strlen(one[i]);
        mvwprintw(stdscr, LINES/2 + y, COLS/2 -  fd / 2, one[i]);
    }
    refresh();
    sleep(1);
}

void one(void)
{
    char *one[] = {"  o0  ",
                "   0  ",
                "   o  ",
                "   0  ",
                "   o  ",
                "   0  ",
                " 0oo00"};
    int fd = 0;

    clear();
    for (int i = 0, y = 0; i < 7; i++, y++) {
        fd = my_strlen(one[i]);
        mvwprintw(stdscr, LINES/2 + y, COLS/2 -  fd / 2, one[i]);
    }
    refresh();
    sleep(1);
}

void launch(char *message, int i)
{
    int r = my_strlen(message);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    clear();
    attron(A_BOLD);
    mvwprintw(stdscr, LINES/2, COLS/2 - r / 2, message);
    refresh();
    attroff(A_BOLD);
    sleep(1);
    attron(A_BOLD | COLOR_PAIR(i));
    three();
    two();
    one();
    zero();
    attroff(A_BOLD | COLOR_PAIR(i));
    return;
}
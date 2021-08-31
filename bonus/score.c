/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** score
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

void writescoreboard(char *buffer)
{
    int r = -1;

    while (r != 'y') {
        attron(A_BOLD);
        for (int j = 0, w = 0, y = 0; y <= 5; j++, w++) {
            if (buffer[j] == '\n') {
                j++;
                y++;
                w = 0;
            }
            printbuffer(buffer, j, w, y);
        }
        attroff(A_BOLD);
        refresh();
        r = getch();
    }
    free(buffer);
    endwin();
    exit(0);
}

char *fillbufferagain(char *buffer, scoreboard sco, int i)
{
    if (i < sco.second && i > sco.third ||
            i == sco.second && sco.third != i) {
        buffer[52] = 'N';
        buffer[53] = 'E';
        buffer[54] = 'W';
        buffer[59] = i / 10 + '0';
        buffer[60] = i % 10 + '0';
    } else if (i < sco.third && i > sco.fourth ||
            i == sco.third && sco.fourth != i) {
        buffer[68] = 'N';
        buffer[69] = 'E';
        buffer[70] = 'W';
        buffer[75] = i / 10 + '0';
        buffer[76] = i % 10 + '0';
    } else if (i < sco.fourth && i > sco.fifth ||
                i == sco.fourth && sco.fifth != i) {
        buffer[84] = 'N';
        buffer[85] = 'E';
        buffer[86] = 'W';
        buffer[91] = i / 10 + '0';
        buffer[92] = i % 10 + '0';
    }
    return (buffer);
}

char *fillbuffer(char *buffer, scoreboard sco, int i)
{
    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == 'N' && buffer[j+1] == 'E' && buffer[j+2] == 'W') {
            buffer[j] = ' ';
            buffer[j+1] = ' ';
            buffer[j+2] = ' ';
        }
    }
    if (i > sco.first) {
        buffer[20] = 'N';
        buffer[21] = 'E';
        buffer[22] = 'W';
        buffer[27] = i / 10 + '0';
        buffer[28] = i % 10 + '0';
    } else if (i < sco.first && i > sco.second ||
            i == sco.first && sco.second != i) {
        buffer[36] = 'N';
        buffer[37] = 'E';
        buffer[38] = 'W';
        buffer[43] = i / 10 + '0';
        buffer[44] = i % 10 + '0';
    } else
        buffer = fillbufferagain(buffer, sco, i);
    return (buffer);
}

scoreboard fillscore(scoreboard score, char *buffer)
{
    score.first = getthefirst(score.first, buffer);
    score.second = getthesecond(score.second, buffer);
    score.third = getthethird(score.third, buffer);
    score.fourth = getthefourth(score.fourth, buffer);
    score.fifth = getthefifth(score.fifth, buffer);
    return (score);
}

void scoresurv(int i, int fd)
{
    close(fd);
    fd = open("maps/highscore", O_RDWR);
    struct stat sb;
    stat("maps/highscore", &sb);
    char *buffer = malloc(sizeof(char *) * sb.st_size);
    read(fd, buffer, sb.st_size);
    scoreboard score = fillscore(score, buffer);

    clear();
    buffer = fillbuffer(buffer, score, i);
    close(fd);
    fd = open("maps/highscore", O_WRONLY);
    write(fd, buffer, sb.st_size);
    close(fd);
    init_pair(15, COLOR_RED, COLOR_BLACK);
    writescoreboard(buffer);
}
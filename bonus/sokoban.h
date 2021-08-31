/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** sokoban
*/

typedef struct {
    int i;
    int j;
    int nbr;
    int r;
    int size;
    char **newmap;
    char **mapo;
    char **maptwo;
    char **mapotwo;
    int k;
    int w;
} variable;
typedef struct {
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
} scoreboard;
char **fillmap(char *buffer, char **newmap, int nbr, int size);
int printmap(char **newmap, int r, int nbr, variable v);
int errorarg(int ac, char *av, int fd, char *avr);
void getwindowsize(int sig);
void checkfile(int fd, int size, char *av);
char **searchfind(char **map, int r, int nbr, variable *v);
int checknumbero(char **map, int nbr, variable *v);
int readmap(char *map, int size, int fd);
int checklose(char **map, int nbr, char **mapo, variable *v);
char **checko(char **map, int i, int j, variable *v);
char **fillmapo(char **newmap, char **mapo, int nbr, int size);
void finderror(char *av, int fd, int size);
void maperror(char *buffer);
void description(void);
char **movebox(char **map, int r, int i, int j);
char **moveboxtwo(char **map, int r, int i, int j);
char **rightkey(char **map, int r, variable *v);
char **leftkey(char **map, int r, variable *v);
variable mapsandnbr(int size, int fd, variable v);
variable completegame(variable v, int fd, char *buffer, int size);
int readmap(char *map, int size, int fd);
int spaceandlose(variable v, int fd, char *map, int size);
char **moveboxright(char **map, int r, int i, int j);
char **moveboxup(char **map, int r, int i, int j);
char **moveboxleft(char **map, int r, int i, int j);
char **moveboxdown(char **map, int r, int i, int j);
void checkmapfull(int fd, char *av, int size);
int loseorwin(int r, int nbr, char **map);
char **printthemap(char **map, int nbr);
void gamewin(char **map, int nbr, char *mess, char *end);
void gamelose(char **map, int nbr, char *message, char *end);
void makebox(void);
void menu(char *message, char *mess, char *space);
void winorlose(int r, int fd, char *av, int size);
void checksizeanderrors(char *av, int fd, int size);
void othermenu(char *message, char *mess, int k);
int waitplayertwo(char *map, int size, int fd);
void threeargerrors(int ac, char *av);
int secondplayer(int ac, char **av, int fd, int size);
int checkcolor(int ac, char **av, int fd, int size);
void launch(char *message, int i);
void hashtagandx(int fd, int w, int y, char map);
void hashtagandxtwo(int fd, int w, int y, char map);
void pandoandspacetwo(int fd, int w, int y, char map);
void pandoandspace(int fd, int w, int y, char map);
int readmapsecond(char *map, int size, int fd);
variable mapsandnbrtwo(int size, int fd, variable v);
void makeboxsecond(void);
char **printthemapsecond(char **map, int nbr);
char **movesecondplayer(char **map, int k, int nbr, variable v);
int spaceandlosetwo(variable v, int fd, char *map, int size);
void freethings(char *buffer, variable *v);
int loseorwintwo(int r, int nbr, char **map, variable v);
char **printthemaptwo(char **map, int nbr);
char **resetmap(char **map, int nbr, int size, char *buffer);
variable checkreset(variable v, int size, char *buffer);
void othermenusurvival(char *message, char *mess, int k);
int waitsurvival(char *av, int size, int fd);
void menutwoplayer(char *message, char *mess, char *space);
int getthefirst(int first, char *buffer);
int getthesecond(int first, char *buffer);
int getthethird(int first, char *buffer);
int getthefourth(int first, char *buffer);
int getthefifth(int first, char *buffer);
void scoresurv(int i, int fd);
int survivalfile(int i, int fd);
void printbuffer(char *buffer, int j, int w, int y);
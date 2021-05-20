/*
** EPITECH PROJECT, 2020
** tools2
** File description:
** navy
*/

#include "my.h"

int bin_case(int i)
{
    if (i == 0)
        return (1);
    if (i == 1)
        return (2);
    if (i == 2)
        return (4);
    if (i == 3)
        return (8);
    if (i == 4)
        return (16);
    if (i == 5)
        return (32);
    if (i == 6)
        return (64);
}

char *binary_to_decimal(char *bin)
{
    int dec = 0;
    char *pos = malloc(sizeof(char) * 3);

    for (int i = 6; i >= 0; i--)
        dec = dec + (bin[i] - 48) * bin_case(i);
    pos[0] = dec / 10 + 48;
    pos[1] = dec % 10 + 48;
    pos[2] = '\0';
    return (pos);
}

char *tmp(char *attack, int i)
{
    attack[0] = attack[0] + 17;
    attack[1] = attack[1] + 1;
    my_putstr(attack);
    if (i == 0)
        my_putstr(": missed\n");
    else
        my_putstr(": hit\n");
    return (attack);
}

char *check_position(char *attack, char *map, int pid_player1, Tool *m)
{
    if (m->x == attack[1] - 48 && m->y == attack[0] - 48) {
        if (map[m->i + m->j] == '.' || map[m->i + m->j] == 'o') {
            map[m->i + m->j] = 'o';
            usleep(2000);
            kill(pid_player1, SIGUSR1);
            tmp(attack, 0);
        }
        else {
            map[m->i + m->j] = 'x';
            usleep(2000);
            kill(pid_player1, SIGUSR2);
            tmp(attack, 1);
        }
    }
    return (map);
}

char *attack_position(char *attack, char *map, int pid_player1)
{
    Tool m;

    for (m.i = 36, m.x = 0; m.i <= 162 ; m.i = m.i + 18, m.x++)
        for (m.j = 2, m.y = 0; m.j < 17; m.j = m.j + 2, m.y++)
            map = check_position(attack, map, pid_player1, &m);
    return (map);
}
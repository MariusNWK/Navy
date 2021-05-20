/*
** EPITECH PROJECT, 2020
** tmp for the error
** File description:
** sous fonction
*/

#include "my.h"

int tmp_pos(char *file, int i, error *struct_error)
{
    if (file[i + 3] != file[i]) {
        struct_error->boolean = 1;
        if (file[i + 4] != file[i + 1])
            return (84);
    }
}

int tmp_max(char *file, int i)
{
    int nb1 = 0;
    int nb2 = 0;
    int nb3 = 0;
    int nb4 = 0;

    if (i == 2 || i == 10 || i == 18 || i == 26) {
        nb1 = file[i];
        nb2 = file[i + 1] - '0';
        nb3 = file[i + 3];
        nb4 = file[i + 4] - '0';
        if (nb1 > nb3 || nb2 > nb4)
            return (84);
    }
    return (0);
}
/*
** EPITECH PROJECT, 2020
** check max
** File description:
** sous fonction
*/

#include "my.h"

int check_total(error *struct_error, char *file, int i)
{
    if (i == 3 || i == 11 || i == 19 || i == 27) {
        if (check_nums(struct_error, file, i) == 84)
            return (84);
        else if (check_caracters_bis(struct_error, file, i) == 84)
            return (84);
    }
    struct_error->boolean = 0;
    return (0);
}

int check_caracters(char *file, int i)
{
    if (i == 1 || i == 4 || i == 9 || i == 12 ||
        i == 17 || i == 20 || i == 25 || i == 28)
        if (file[i] != ':')
            return (84);
    return (0);
}

int check_pos(error *struct_error, char *file, int i)
{
    int nb1 = 0;
    int nb2 = 0;

    if (i == 2 || i == 10 || i == 18 || i == 26)
        if (tmp_pos(file, i, struct_error) == 84)
            return (84);
    return (0);
}

int check_max(char *file)
{
    for (int i = 0; i < 31; i++)
        if (tmp_max(file, i) == 84)
            return (84);
    return (0);
}
/*
** EPITECH PROJECT, 2020
** error tool
** File description:
** sous fonction
*/

#include "my.h"

int check_max_bis(int nb1, int nb2)
{
    if (nb1 >= nb2)
        return (nb1);
    else
        return (nb2);
}

int check_min(int nb1, int nb2)
{
    if (nb1 < nb2)
        return (nb1 - 1);
    else
        return (nb2 - 1);
}

int check_caracters_bis(error *struct_error, char *file, int i)
{
    int total = 0;
    int nb1 = 0;
    int nb2 = 0;

    if (struct_error->boolean == 1) {
        total = file[i - 3] - '0';
        nb1 = file[i - 1];
        nb2 = file[i + 2];
        if (check_max_bis(nb1, nb2) - total != check_min(nb1, nb2)) {
            struct_error->boolean = 0;
            return (84);
        }
    }
    return (0);
}

int check_nums(error *struct_error, char *file, int i)
{
    int total = 0;
    int nb1 = 0;
    int nb2 = 0;

    if (struct_error->boolean == 0) {
        total = file[i - 3] - '0';
        nb1 = file[i] - '0';
        nb2 = file[i + 3] - '0';
        if (check_max_bis(nb1, nb2) - check_min(nb1, nb2) != total) {
            struct_error->boolean = 0;
            return (84);
        }
    }
    return (0);
}
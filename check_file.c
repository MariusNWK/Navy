/*
** EPITECH PROJECT, 2020
** check file
** File description:
** sous fonction
*/

#include "my.h"

int tmp_check_file(char *file, int x, int i)
{
    if (x == 0)
        if (file[i] < '0' || file[i] > '9')
            return (84);
    return (0);
}

int is_same_nbr(int i, char *file)
{
    for (int j = 0, same_nbr = 0; j < 32; j = j + 8) {
        if (file[i] == file[j]) {
            same_nbr++;
        }
        if (same_nbr > 1) {
            return (84);
        }
    }
    return (0);
}

int check_file(char *file)
{
    error *struct_error = malloc(sizeof(error));
    int x = 0;

    struct_error->boolean = 0;
    for (int i = 0; i < 32; i = i + 8)
        if (is_same_nbr(i, file) == 84)
            return (84);    
    for (int i = 0; i < 31; i++, x++) {
        if (check_caracters(file, i) == 84)
            return (84);
        if (check_total(struct_error, file, i) == 84)
            return (84);
        if (check_pos(struct_error, file, i) == 84)
            return (84);
        if (tmp_check_file(file, x, i) ==  84)
            return (84);
        if (file[i] == '\n')
            x = -1;
    }
    free(struct_error);
    return (0);
}
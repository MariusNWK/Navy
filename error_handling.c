/*
** EPITECH PROJECT, 2020
** error_handling
** File description:
** navy
*/

#include "my.h"

int check_pid(char **av)
{
    int signal = my_getnbr(av[1]);

    if (signal <= 31)
        return (84);
    return (0);
}

int error_handling(char **av, Player *j, char *usefull, int ac)
{
    char *file = read_file(usefull);
    int max = check_max(file);
    int files = check_file(file);

    if (my_strlen(file) != 32) {
        return (84);
    } else if (ac == 2) {
        if (files == 84 || max == 84)
            return (84);
    } else
        if (files == 84 || max == 84 || check_pid(av) == 84)
            return (84);
    return (0);
}
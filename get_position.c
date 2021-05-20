/*
** EPITECH PROJECT, 2020
** get_position
** File description:
** navy
*/

#include "my.h"

int is_good_position(char *position)
{
    if (my_strlen(position) != 3)
        return (0);
    if (position[0] != 'A' && position[0] != 'B' &&
        position[0] != 'C' && position[0] != 'D' &&
        position[0] != 'E' && position[0] != 'F' &&
        position[0] != 'G' && position[0] != 'H')
        return (0);
    if (position[1] != '1' && position[1] != '2' &&
        position[1] != '3' && position[1] != '4' &&
        position[1] != '5' && position[1] != '6' &&
        position[1] != '7' && position[1] != '8')
        return (0);
    return (1);
}

char *get_position(void)
{
    size_t bufsize = 32;
    char *buffer = (char *)malloc(sizeof(char) * bufsize);

    my_putstr("\nattack: ");
    getline(&buffer, &bufsize, stdin);
    if (is_good_position(buffer) == 0) {
        my_putstr("wrong position");
        free(buffer);
        get_position();
    } else
        return (buffer);
}
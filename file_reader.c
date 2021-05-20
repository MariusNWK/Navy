/*
** EPITECH PROJECT, 2020
** create_map
** File description:
** navy
*/

#include "my.h"

size_t getfilesize(char const *filepath)
{
    struct stat st;

    if (stat(filepath, &st) != 0)
        return (0);
    return (st.st_size);
}

char *read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;

    str = malloc(getfilesize(filepath) + 1);
    read(fd, str, getfilesize(filepath));
    str[getfilesize(filepath)] = '\0';
    close(fd);
    return (str);
}

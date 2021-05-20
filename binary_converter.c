/*
** EPITECH PROJECT, 2020
** binary_converter
** File description:
** navy
*/

#include "my.h"

char *special_cases(int n)
{
    if (n == 0)
        return (my_strdup("0"));
    if (n == 1)
        return (my_strdup("1"));
    if (n == 2)
        return (my_strdup("10"));
}

char *binary_converter(int n)
{
    char *result;
    int i = 0;
    unsigned int size = 0;
    int n_bis = n;

    if (n == 0 || n == 1 || n == 2) {
        return (special_cases(n));
    }
    for (; n_bis > 0; size++)
        n_bis = n_bis / 2;
    size = size + 1;
    result = malloc(sizeof(char) * (size + 1));
    for (i = 0; n > 0; i++, n /= 2)
        result[i] = (n % 2) + 48;
    result[i] = '\0';
    return (result);
}
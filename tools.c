/*
** EPITECH PROJECT, 2020
** tools
** File description:
** navy
*/

#include "my.h"

void display_nbr(int nbr)
{
    int len_nbr = 0;
    int num = 1;
    char c;

    for (int n = nbr; n > 0; n = n / 10)
        len_nbr++;
    for (int i = 1; i < len_nbr; i++)
        num = num * 10;
    for (int i = 0; i < len_nbr; i++) {
        c = nbr / num + 48;
        my_putchar(c);
        nbr = nbr % num;
        num = num / 10;
    }
    my_putchar('\n');
}
/*
** EPITECH PROJECT, 2020
** main
** File description:
** navy
*/

#include "my.h"

int main(int ac, char **av)
{
    Player j;
    int wog = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        helper();
    } else if (ac == 2) {
        if (error_handling(av, &j, av[1], ac) == 84) {
            write(2, "Invalid\n", 8);
            return (84);
        }
        wog = program_player1(&j, av[1]);
    } else {
        if (error_handling(av, &j, av[2], ac) == 84) {
            write(2, "Invalid\n", 8);
            return (84);
        }
        j.pid_player1 = my_getnbr(av[1]);
        wog = program_player2(&j, av[2]);
    }
    return (wog);
}
/*
** EPITECH PROJECT, 2020
** programP2
** File description:
** navy
*/

#include "my.h"

void display_pid_p2(void)
{
    pid_t pid = getpid();

    my_putstr("my_pid: ");
    display_nbr(pid);
}

void handle_sigusr2(int sig)
{
    write(1, "successfully connected\n\n", 24);
}

void connection_to_p1(int ppid)
{
    struct sigaction sa = { 0 };

    kill(ppid, SIGUSR1);
    sa.sa_handler = &handle_sigusr2;
    sigaction(SIGUSR2, &sa, NULL);
    pause();
}

int program_player2(Player *j, char *pos2)
{
    int wog = 0;

    display_pid_p2();
    connection_to_p1(j->pid_player1);
    wog = game_p2_pov(j, pos2);
    return (wog);
}
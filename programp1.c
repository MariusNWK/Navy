/*
** EPITECH PROJECT, 2020
** programP1
** File description:
** navy
*/

#include "my.h"

general_t g;

void display_pid_p1(void)
{
    pid_t pid = getpid();

    my_putstr("my_pid: ");
    display_nbr(pid);
    my_putstr("waiting for enemy connection...\n\n");
}

void get_pid(int sig, siginfo_t *info, void *context)
{
    kill(info->si_pid, SIGUSR2);
    write(1, "enemy connected\n\n", 17);
    g.pid_p2 = info->si_pid;
}

void connection_to_p2(Player *j)
{
    struct sigaction sa = { 0 };

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    j->pid_player2 = g.pid_p2;
}

int program_player1(Player *j, char *pos1)
{
    int wog = 0;

    display_pid_p1();
    connection_to_p2(j);
    wog = game_p1_pov(j, pos1);
    return (wog);
}
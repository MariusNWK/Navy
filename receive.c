/*
** EPITECH PROJECT, 2020
** receive
** File description:
** sous fonction
*/

#include "my.h"

void zero(int sig, siginfo_t *info, void *context)
{
    g.bv[g.z] = '0';
    g.z++;
}

void one(int sig, siginfo_t *info, void *context)
{
    g.bv[g.z] = '1';
    g.z++;
}

char *receive_bv(int pid_player1)
{
    struct sigaction sa0 = { 0 };
    struct sigaction sa1 = { 0 };

    g.z = 0;
    for (int i = 0; i < 7; i++) {
        sa0.sa_sigaction = zero;
        sa1.sa_sigaction = one;
        sigaction(SIGUSR1, &sa0, NULL);
        sigaction(SIGUSR2, &sa1, NULL);
        pause();
    }
    return (g.bv);
}
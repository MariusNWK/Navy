/*
** EPITECH PROJECT, 2020
** send_attack_to_P2
** File description:
** navy
*/

#include "my.h"

void missed(int sig, siginfo_t *info, void *context)
{
    write(1, " missed\n", 8);
    g.is_hit = 0;
}

void hit(int sig, siginfo_t *info, void *context)
{
    write(1, " hit\n", 5);
    g.is_hit = 1;
}

char *display_symbol(char *attack, char *enemy_map)
{
    Tool m;

    for (m.i = 36, m.x = 0; m.i <= 162 ; m.i = m.i + 18, m.x++)
        for (m.j = 2, m.y = 0; m.j < 17; m.j = m.j + 2, m.y++)
            enemy_map = display_symbol_two(&m, attack, enemy_map);
    return (enemy_map);
}

char *hit_or_missed(char *attack, char *enemy_map)
{
    struct sigaction sa0 = { 0 };
    struct sigaction sa1 = { 0 };

    sa0.sa_sigaction = missed;
    sa1.sa_sigaction = hit;
    sigaction(SIGUSR1, &sa0, NULL);
    sigaction(SIGUSR2, &sa1, NULL);
    pause();
    enemy_map = display_symbol(attack, enemy_map);
    return (enemy_map);
}

char *send_attack(char *attack, int pid_player, char *enemy_map)
{
    char *bv;

    attack[0] = attack[0] - 17;
    attack[1] = attack[1] - 1;
    bv = binary_converter(my_getnbr(attack));
    for (int i = 0; i < 7; i++) {
        if (bv[i] == '1')
            kill(pid_player, SIGUSR2);
        else
            kill(pid_player, SIGUSR1);
        usleep(1000);
    }
    enemy_map = hit_or_missed(attack, enemy_map);
    return (enemy_map);
}
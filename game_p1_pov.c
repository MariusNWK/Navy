/*
** EPITECH PROJECT, 2020
** game_P1_POV
** File description:
** navy
*/

#include "my.h"

int is_hit(char *map, int i, int j, int croix)
{
    if (map[i + j] == 'x')
        croix++;
    return (croix);
}

int did_i_win(char *enemy_map, char *map)
{
    int croix = 0;

    for (int i = 36, x = 0; i <= 162 ; i = i + 18, x++)
        for (int j = 2, y = 0; j < 17; j = j + 2, y++)
            croix = is_hit(enemy_map, i, j, croix);
    if (croix >= 14) {
        my_putstr("my positions:\n");
        my_putstr(map);
        my_putstr("\nenemy's positions:\n");
        my_putstr(enemy_map);
        my_putstr("\nI won\n\n");
        return (1);
    } else
        return (0);
}

int did_i_lose(char *map, char *enemy_map)
{
    int croix = 0;

    for (int i = 36, x = 0; i <= 162 ; i = i + 18, x++)
        for (int j = 2, y = 0; j < 17; j = j + 2, y++)
            croix = is_hit(map, i, j, croix);
    if (croix >= 14) {
        my_putstr("my positions:\n");
        my_putstr(map);
        my_putstr("\nenemy's positions:\n");
        my_putstr(enemy_map);
        my_putstr("\nEnemy won\n\n");
        return (1);
    } else
        return (0);
}

int player1_to_play(char *map, char *enemy_map, int i, Player *j)
{
    char *enemy_attack;
    char *bv;
    char *attack;

    display(map, enemy_map, 1);
    attack = get_position();
    attack[2] = ':';
    my_putstr(attack);
    enemy_map = send_attack(attack, j->pid_player2, enemy_map);
    my_putstr("\nwaiting for enemy's attack...\n");
    bv = receive_bv(j->pid_player2);
    enemy_attack = binary_to_decimal(bv);
    map = attack_position(enemy_attack, map, j->pid_player2);
    my_putchar('\n');
    if (did_i_win(enemy_map, map) == 1) {
        return (0);
    } else if (did_i_lose(map, enemy_map) == 1) {
        return (1);
    } else
        return (player1_to_play(map, enemy_map, i, j));
}

int game_p1_pov(Player *j, char *pos1)
{
    int i = 0;
    char *map = read_file("./map.txt");
    char *enemy_map = read_file("./map.txt");
    int wog = 0;

    map = add_boats(map, pos1);
    wog = player1_to_play(map, enemy_map, i, j);
    free(map);
    free(enemy_map);
    return (wog);
}
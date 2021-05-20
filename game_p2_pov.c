/*
** EPITECH PROJECT, 2020
** game_P2_POV
** File description:
** navy
*/

#include "my.h"

void display(char *map, char *enemy_map, int i)
{
    my_putstr("my_positions:\n");
    my_putstr(map);
    my_putstr("\nenemy's positions:\n");
    my_putstr(enemy_map);
    if (i == 2)
        my_putstr("\nwaiting for enemy's attack...\n");
}

int player2_to_play(char *map, char *enemy_map, int i, Player *j)
{
    char *enemy_attack;
    char *attack;
    char *bv;

    display(map, enemy_map, 2);
    bv = receive_bv(j->pid_player1);
    enemy_attack = binary_to_decimal(bv);
    map = attack_position(enemy_attack, map, j->pid_player1);
    attack = get_position();
    attack[2] = ':';
    my_putstr(attack);
    enemy_map = send_attack(attack, j->pid_player1, enemy_map);
    my_putchar('\n');
    if (did_i_win(enemy_map, map) == 1) {
        return (0);
    } else if (did_i_lose(map, enemy_map) == 1) {
        return (1);
    } else
        return (player2_to_play(map, enemy_map, i, j));
}

int game_p2_pov(Player *j, char *pos2)
{
    int i = 0;
    int wog = 0;
    char *map = read_file("./map.txt");
    char *enemy_map = read_file("./map.txt");

    map = add_boats(map, pos2);
    wog = player2_to_play(map, enemy_map, i, j);
    free(map);
    free(enemy_map);
    return (wog);
}
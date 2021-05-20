/*
** EPITECH PROJECT, 2020
** minor_deleter
** File description:
** navy
*/

#include "my.h"

void coords_top(int k, Boat *b, Tool *m, char *str_pos)
{
    if (str_pos[k + 2] == m->i + 65 && str_pos[k + 3] - 1 == m->j + 48) {
        b->top.x = m->j;
        b->top.y = m->i;
    }
}

void coords_bot(int k, Boat *b, Tool *m, char *str_pos)
{
    if (str_pos[k + 5] == m->i + 65 && str_pos[k + 6] - 1 == m->j + 48) {
        b->bot.x = m->j;
        b->bot.y = m->i;
    }
}

char *display_symbol_two(Tool *m, char *attack, char *enemy_map)
{
    if (m->x == attack[1] - 48 && m->y == attack[0] - 48) {
        if (g.is_hit == 0) {
            enemy_map[m->i + m->j] = 'o';
        } else {
            enemy_map[m->i + m->j] = 'x';
        }
    }
    return (enemy_map);
}
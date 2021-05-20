/*
** EPITECH PROJECT, 2020
** add_boats
** File description:
** navy
*/

#include "my.h"

void attribute_coords(char *str_pos, int k, Boat *b)
{
    char column = 0;
    int line = 0;
    Tool m;

    b->size = str_pos[k] - 48;
    for (m.i = 0; m.i < 8; m.i++)
        for (m.j = 0; m.j < 8; m.j++)
            coords_top(k, b, &m, str_pos);
    for (m.i = 0; m.i < 8; m.i++)
        for (m.j = 0; m.j < 8; m.j++)
            coords_bot(k, b, &m, str_pos);
}

void add_size(int i, int j, int size, Tool *m)
{
    if (m->x == m->kx && m->y == m->ky)
        m->map[i + j] = size;
}

char *add_on_map(char *map, int kx, int ky, char size)
{
    Tool m;
    int i;
    int j;

    m.map = my_strdup(map);
    free(map);
    m.kx = kx;
    m.ky = ky;
    for (i = 36, m.x = 0; i <= 162 ; i = i + 18, m.x++)
        for (j = 2, m.y = 0; j < 17; j = j + 2, m.y++)
            add_size(i, j, size, &m);
    return (m.map);
}

char *display_boats(char *map, Boat *b)
{
    if (b->top.x == b->bot.x) {
        for (int i = 0, x = b->top.x, y = b->top.y; i < b->size; i++, y++)
            map = add_on_map(map, x, y, b->size + 48);
    } else
        for (int i = 0, x = b->top.x, y = b->top.y; i < b->size; i++, x++)
            map = add_on_map(map, x, y, b->size + 48);
    return (map);
}

char *add_boats(char *map, char *pos1)
{
    Boat b;
    char *str_pos = read_file(pos1);

    for (int i = 0; str_pos[i] != '\0'; i = i + 8) {
        attribute_coords(str_pos, i, &b);
        map = display_boats(map, &b);
    }
    free(str_pos);
    return (map);
}
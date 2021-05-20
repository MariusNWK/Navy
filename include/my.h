/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);

////////////////////////////////////////////////////////////

typedef struct {
    int boolean;
} error;

int check_nums(error *, char *, int);
int check_caracters_bis(error *, char *, int);
int check_min(int, int);
int check_max_bis(int, int);
int check_file(char *);
int check_total(error *, char *, int);
int check_caracters(char *, int);
int check_pos(error *, char *, int);
int check_max(char *);
int tmp_pos(char *, int, error *);
int tmp_max(char *, int);

////////////////////////////////////////////////////////////

typedef struct Player {
    int player1;
    int player2;
    int pid_player1;
    int pid_player2;
} Player;

int program_player1(Player *, char *);
int program_player2(Player *, char *);
int game_p1_pov(Player *, char *);
int game_p2_pov(Player *, char *);

////////////////////////////////////////////////////////////

void display(char *, char *, int);
int error_handling(char **, Player *, char *, int);
void display_nbr(int);

////////////////////////////////////////////////////////////

typedef struct Coords {
    int x;
    int y;
} Coords;

typedef struct Boat {
    int size;
    Coords top;
    Coords bot;
} Boat;

char *add_boats(char *, char *);

////////////////////////////////////////////////////////////

char *binary_converter(int);
char *send_attack(char *, int, char *);
char *read_file(char const *);
char *get_position(void);
char *attack_position(char *, char *, int);

////////////////////////////////////////////////////////////

int did_i_win(char *, char *);
int did_i_lose(char *, char *);
char *receive_bv(int);
char *binary_to_decimal(char *);

typedef struct General {
    int pid_p2;
    char bv[7];
    int z;
    int is_hit;
} general_t;

extern general_t g;

typedef struct Tool {
    char *map;
    int x;
    int y;
    int kx;
    int ky;
    int i;
    int j;
} Tool;

////////////////////////////////////////////////////////////

void coords_top(int, Boat *, Tool *, char *);
void coords_bot(int, Boat *, Tool *, char *);
char *display_symbol_two(Tool *, char *, char *);
void helper(void);
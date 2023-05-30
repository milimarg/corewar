/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_print_arena_second.c
*/

#include "vm.h"

void ft_print_lives(t_env *e, int i)
{
    int k = -1;
    int cycles = (e->player[i].live < 161) ? e->player[i].live : 161;

    attron(COLOR_PAIR(e->player[i].color));
    printw("\nLives for %-15s", e->player[i].name);
    printw("%-5d", e->player[i].live);
    while (++k < cycles)
        addch(ACS_CKBOARD);
    attroff(COLOR_PAIR(e->player[i].color));
}

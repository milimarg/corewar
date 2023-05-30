/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** init_e.c
*/

#include "vm.h"

void init_players(t_env *e)
{
    for (int i = 0; i < e->player_amount; i++) {
        e->player[i].live = 0;
        e->player[i].color = 1 + (i % 6);
    }
}

void ft_szero(t_env *e)
{
    for (int i = 0; i < MEM_S; i++) {
        e->a[i].hex = 0;
        e->a[i].color = 12;
        e->a[i].prevcolor = 12;
        e->a[i].occupied = 0;
        e->a[i].new_color_count = 0;
    }
}

void init_e(t_env *e, char **av)
{
    e->files = av;
    e->cycle = 0;
    e->lives = 0;
    e->bonus_2d = 0;
    e->bonus_3d = 0;
    e->dump = 0;
    e->winner = -1;
    e->check = 0;
    e->tot_cycle = 0;
    e->head = NULL;
    e->cycles_to_die = CYCLE_TO_DIE;
    ft_szero(e);
    set_op_tab(e);
}

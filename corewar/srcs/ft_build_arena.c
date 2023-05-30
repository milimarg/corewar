/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_build_arena.c
*/

#include "vm.h"

void ft_player_to_arena(t_env *e, int i, int *k)
{
    int count = 0;

    for (; count < e->player[i].inst_len; count++) {
        e->a[*k].hex = 0xFF & e->player[i].inst[count];
        e->a[*k].color = 1 + (i % 6);
        e->a[*k].prevcolor = 1 + (i % 6);
        *k += 1;
    }
}

void ft_build_arena(t_env *e)
{
    static int k = 0;

    for (int i = 0; i < e->player_amount; i++) {
        e->player[i].index_start = (MEM_S / e->player_amount) * i;
        e->player[i].live = 0;
        k = (MEM_S / e->player_amount) * i;
        ft_player_to_arena(e, i, &k);
    }
}

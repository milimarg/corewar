/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** parse_flags_second.c
*/

#include "vm.h"

int ft_loop_dup(t_env *e, int nbr)
{
    int k = -1;

    while (++k < e->player_amount)
        if (nbr == e->player[k].nbr)
            return (1);
    return (0);
}

int smallest_number(t_env *e)
{
    int i = 0;
    int small = e->player[i].nbr;

    while (++i < e->player_amount)
        if (small > e->player[i].nbr)
            small = e->player[i].nbr;
    return (small);
}

void ft_check_number(t_env *e, char *nbr)
{
    int i = -1;

    while (nbr[++i])
        if (!(ft_strchr(LABEL_NUMBERS, nbr[i])))
            ft_exit(e, 14);
}

void ft_add_bonus(t_env *e, int args, int *i, int is_2d_or_3d)
{
    if ((*i + 2) > args)
        ft_exit(e, 18);
    if (!is_2d_or_3d) {
        e->bonus_2d = 1;
    } else {
        e->bonus_3d = 1;
    }
    *i += 1;
}

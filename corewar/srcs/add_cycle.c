/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** add_cycle.c
*/

#include "vm.h"

int ft_check_if_an_operation(t_env *e, t_cursor *cursor)
{
    int i = e->a[cursor->index].hex & 0xFF;

    return ((i > 0 && i < 17));
}

void ft_add_cycle(t_env *e, t_cursor *cursor)
{
    if (ft_check_if_an_operation(e, cursor)) {
        cursor->cycle += e->op_tab[e->a[cursor->index].hex & 0xFF].cycles - 2;
        cursor->running = 1;
    } else
        ft_update_cursor(e, cursor, 1);
}

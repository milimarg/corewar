/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_aff.c
*/

#include "../srcs/vm.h"

void ft_aff(t_env *e, t_cursor *cursor)
{
    int index_extra = 0;
    int r = ZMASK(e->a[MODA(cursor->index + 2)].hex);
    int acb = ZMASK(e->a[MODA(cursor->index + 1)].hex);

    if (r < 0 || r > 15 || acb != 64)
        ft_update_cursor(e, cursor, 3);
    else {
        index_extra = get_reg(e, cursor, 2) % 256;
        if (e->bonus_2d)
            printw("Aff: %C\n", index_extra);
        else
            ft_printf("Aff: %C\n", index_extra);
        ft_update_cursor(e, cursor, 3);
    }
}

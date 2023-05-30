/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_zjmp.c
*/

#include "../srcs/vm.h"

void ft_zjmp(t_env *e, t_cursor *cursor)
{
    int index_extra = 0;

    if (cursor->carry) {
        index_extra = get_dir(e, cursor, 1, 2);
        index_extra = MODX(index_extra);
        ft_update_cursor(e, cursor, index_extra);
    } else
        ft_update_cursor(e, cursor, 3);
}

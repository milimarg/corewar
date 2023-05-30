/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_lfork.c
*/

#include "../srcs/vm.h"

void ft_lfork(t_env *e, t_cursor *cursor)
{
    ft_fork_both(e, cursor, 1);
}

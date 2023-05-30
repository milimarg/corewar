/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_error_handle.c
*/

#include "ft_print.h"

int ft_error_handle(t_vars *e)
{
    if (e->type == -1)
        return (TRUE);
    if (e->type >= 3 && e->type <= 6 && e->zero)
        return (TRUE);
    if (e->type == POINTER && e->flags > 0)
        return (TRUE);
    if (e->type == POINTER && e->pointlen != -1)
        return (TRUE);
    return (FALSE);
}

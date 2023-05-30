/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_ldi_plus.c
*/

#include "../srcs/vm.h"

static int check_register_ldi_2(t_env *e, t_cursor *cursor, char acb)
{
    if ((DRR == ZMASK(acb) || IRR == ZMASK(acb)) &&
    (!is_reg_valid(e->a[MODA(cursor->index)].hex) ||
    !is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
        return (0);
    else if (DDR == ZMASK(acb) &&
    !is_reg_valid(e->a[MODA((cursor->index + 1))].hex))
        return (0);
    else
        return (1);
}

int check_register_ldi(t_env *e, t_cursor *cursor, char acb)
{
    if (RRR == ZMASK(acb) && (!is_reg_valid(e->a[MODA(cursor->index)].hex ||
    !is_reg_valid(e->a[MODA(cursor->index - 1)].hex)) ||
    !is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
        return (0);
    else if (RDR == ZMASK(acb) &&
    (!is_reg_valid(e->a[MODA(cursor->index - 2)].hex) ||
    !is_reg_valid(e->a[MODA(cursor->index + 1)].hex)))
        return (0);
    else
        return (check_register_ldi_2(e, cursor, acb));
}

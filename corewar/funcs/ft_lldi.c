/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_lldi.c
*/

#include "../srcs/vm.h"

static void ft_load(t_env *e, t_cursor *cursor, int ind, int r2)
{
    int value = get_bytes(e, cursor, cursor->index - ind + r2);

    cursor->reg[e->a[MODA(cursor->index)].hex - 1] = value;
    cursor->carry = (value == 0);
}

void ft_lldi(t_env *e, t_cursor *cursor)
{
    char acb = e->a[MODA(cursor->index + 1)].hex;
    int r2 = 0;
    int ind = 1;

    if (RRR == ZMASK(acb)) {
        r2 = get_reg(e, cursor, 2) + get_reg(e, cursor, 3);
        ft_update_cursor(e, cursor, 4);
        ind = 4;
    } else if (RDR == ZMASK(acb) || DRR == ZMASK(acb) || IRR == ZMASK(acb))
        r2 = rdr_drr_irr(e, cursor, acb, &ind);
    else
        r2 = (DDR == ZMASK(acb) || IDR == ZMASK(acb)) ?
        ddr_idr(e, cursor, acb, &ind) : r2;
    if (check_register_ldi(e, cursor, acb))
        ft_load(e, cursor, ind, r2);
    ft_update_cursor(e, cursor, 1);
}

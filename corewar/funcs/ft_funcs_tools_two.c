/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_funcs_tools_two.c
*/

#include "../srcs/vm.h"

void ft_init_v(t_env *e, t_cursor *cursor, t_var *v)
{
    v->r1 = 0;
    v->r2 = 0;
    v->r3 = 0;
    v->ind = 0;
    v->acb = e->a[MODA(cursor->index + 1)].hex;
    v->carry = 0;
}

int is_reg_valid(int i)
{
    return (i > 0 && i <= REG_NUMBER);
}

int get_ind_sti(t_env *e, t_cursor *cursor, int i)
{
    unsigned short r = ((ZMASK(e->a[MODA(cursor->index + i)].hex) << 8) |
    ZMASK(e->a[MODA(cursor->index + i + 1)].hex));
    short r2 = (short)r;
    int byte = get_bytes(e, cursor, MODX(cursor->index + r2));

    return (byte);
}

int get_dir_sti(t_env *e, t_cursor *cursor, int i)
{
    unsigned short r = (ZMASK(e->a[MODA(cursor->index + i)].hex) << 8) |
    ZMASK(e->a[MODA(cursor->index + i + 1)].hex);
    short r2 = (short)r;

    return (MODX(r2));
}

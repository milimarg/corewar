/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_ld.c
*/

#include "../srcs/vm.h"

/*
** Instructions:
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
*/

static void ft_ld_2(t_env *e, t_cursor *cursor)
{
    int value = 0;
    int opc_ind = cursor->index;
    unsigned short r = 0;
    char r1 = 0;
    char acb = e->a[MODA(opc_ind + 1)].hex;

    if (IR == ZMASK(acb)) {
        r = ((ZMASK(e->a[MODA(opc_ind + 2)].hex) << 8) |
        ZMASK(e->a[MODA(opc_ind + 3)].hex));
        value = get_bytes(e, cursor, MODX(((short)r)) + opc_ind);
        r1 = e->a[MODA(opc_ind + 2 + 2)].hex - 1;
        if (ft_is_reg(r1, r1, r1)) {
            cursor->reg[e->a[MODA(opc_ind + 2 + 2)].hex - 1] = value;
            cursor->carry = (value == 0);
        }
        ft_update_cursor(e, cursor, 5);
    }
}

void ft_ld(t_env *e, t_cursor *cursor)
{
    int value = 0;
    int opc_ind = cursor->index;
    char r1 = 0;
    char acb = e->a[MODA(opc_ind + 1)].hex;

    if (DR == ZMASK(acb)) {
        value = get_bytes(e, cursor, opc_ind + 2);
        r1 = e->a[MODA(opc_ind + 2 + 4)].hex - 1;
        if (ft_is_reg(r1, r1, r1)) {
            cursor->reg[e->a[MODA(opc_ind + 2 + 4)].hex - 1] = value;
            cursor->carry = (value == 0);
        }
        ft_update_cursor(e, cursor, 7);
    } else
        ft_ld_2(e, cursor);
}

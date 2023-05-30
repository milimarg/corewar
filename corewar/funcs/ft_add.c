/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_add.c
*/

#include "../srcs/vm.h"

/*
** Instructions: Opcode 4. Take three registries, add the first two, and place
** the result in the third, right before modifying the carry.
*/

void ft_add(t_env *e, t_cursor *cursor)
{
    int opc_ind = cursor->index;
    int r1 = e->a[MODA(opc_ind + 2)].hex - 1;
    int r2 = e->a[MODA(opc_ind + 3)].hex - 1;
    int r3 = e->a[MODA(opc_ind + 4)].hex - 1;

    if (!ft_is_reg(r1, r2, r3)) {
        ft_update_cursor(e, cursor, 5);
        return;
    }
    cursor->reg[r3] = cursor->reg[r1] + cursor->reg[r2];
    cursor->carry = (!cursor->reg[r3]);
    ft_update_cursor(e, cursor, 5);
}

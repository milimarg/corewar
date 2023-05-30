/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_xor_plus.c
*/

#include "../srcs/vm.h"

void fill_r3_xor(t_cursor *cursor, t_var v, int a, int b)
{
    v.carry = 1;

    if (ft_is_reg(v.r1 - 1, v.r3 - 1, v.r3 - 1) && v.carry)
        cursor->reg[v.r3 - 1] = a ^ b;
}

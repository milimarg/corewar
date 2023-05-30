/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** init_reg.c
*/

#include "vm.h"

void init_reg(t_cursor *cursor)
{
    int i = -1;

    while (++i < 16)
        cursor->reg[i] = 0;
}

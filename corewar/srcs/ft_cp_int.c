/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_cp_int.c
*/

#include "vm.h"

int ft_cp_int(int int_start, t_env e)
{
    int i = 4;
    int value = 0;

    while (--i >= 0)
        value += e.a[MODA(int_start + (3 - i))].hex << (i * 8);
    return (value);
}

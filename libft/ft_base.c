/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_base.c
*/

#include "libft.h"

void ft_base(unsigned int i, unsigned int base_length, char *base)
{
    if (i > base_length) {
        ft_base(i / base_length, base_length, base);
        ft_base(i % base_length, base_length, base);
    } else
        ft_putchar(base[i]);
}

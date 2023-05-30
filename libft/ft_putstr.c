/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_putstr.c
*/

#include "libft.h"

void ft_putstr(char const *s)
{
    if (!s)
        ft_putstr("(Null)");
    else
        write(1, s, ft_strlen(s));
}

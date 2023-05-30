/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strequ.c
*/

#include "libft.h"

int ft_strequ(char const *s1, char const *s2)
{
    return (((s1 && s2 && ft_strcmp(s1, s2) == 0)));
}

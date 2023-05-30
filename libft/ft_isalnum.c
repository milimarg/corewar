/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_isalnum.c
*/

#include "libft.h"

int ft_isalnum(int c)
{
    return ((ft_isalpha(c) || ft_isdigit(c)));
}

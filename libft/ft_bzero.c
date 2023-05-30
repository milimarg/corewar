/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_bzero.c
*/

#include "libft.h"

void *ft_bzero(void *s, size_t n)
{
    return (ft_memset(s, 0, n));
}

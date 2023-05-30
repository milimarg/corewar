/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strnew.c
*/

#include "libft.h"

char *ft_strnew(size_t n)
{
    char *s = ft_memalloc(n + 1);

    if (s == NULL)
        return (NULL);
    else
        s[n] = '\0';
    return (s);
}

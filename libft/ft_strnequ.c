/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strnequ.c
*/

#include <string.h>
#include "libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    if (s1 == NULL || s2 == NULL)
        return (0);
    return ((ft_strncmp(s1, s2, n) == 0));
}

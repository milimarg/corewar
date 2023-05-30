/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strncmp.c
*/

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    if (n && (s1[0] || s2[0]) && s1[0] != s2[0])
        return ((unsigned char)s1[0] - (unsigned char)s2[0]);
    if (n && s1[0] && s1[0] == s2[0])
        return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
    return (0);
}

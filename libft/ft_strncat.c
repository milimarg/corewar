/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strncat.c
*/

#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    unsigned int len = ft_strlen(dest);

    for (; src[i] != '\0' && i < n; i++)
        dest[i + len] = src[i];
    dest[i + len] = '\0';
    return (dest);
}

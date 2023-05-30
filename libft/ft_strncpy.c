/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strncpy.c
*/

#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t len)
{
    size_t i = 0;

    for (; src[i] != '\0' && i < len; i++)
        dest[i] = src[i];
    while (i < len) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

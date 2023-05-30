/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memmove.c
*/

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i = 0;

    if (dst > src) {
        for (i = len - 1; i + 1 > 0; i--)
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        return (dst);
    }
    for (i = 0; i < len; i++)
        ((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
    return (dst);
}

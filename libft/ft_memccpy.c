/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memccpy.c
*/

#include <string.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t len)
{
    unsigned char *dest2 = (unsigned char *)dest;
    unsigned char *src2 = (unsigned char *)src;

    for (size_t i = 0; i < len; i++) {
        dest2[i] = src2[i];
        if (src2[i] == (unsigned char)c)
            return (dest + i + 1);
    }
    return (NULL);
}

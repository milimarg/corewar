/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memcpy.c
*/

#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t len)
{
    unsigned char *dest2 = (unsigned char*)dest;
    unsigned char *src2 = (unsigned char*)src;

    for (size_t i = 0; i < len; i++)
        dest2[i] = src2[i];
    return (dest);
}

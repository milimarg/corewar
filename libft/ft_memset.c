/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memset.c
*/

#include <strings.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *b = (unsigned char*)s;

    for (size_t i = 0; i < n; i++)
        *b++ = (unsigned char)c;
    return (s);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memchr.c
*/

#include <string.h>

void *ft_memchr(const void *str, int c, size_t n)
{
    unsigned char *str2 = (unsigned char*)str;

    for (size_t i = 0; i < n; i++) {
        if ((unsigned char)c == str2[i])
            return (str2 + i);
    }
    return (NULL);
}

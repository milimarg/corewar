/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strrchr.c
*/

#include <string.h>
#include "libft.h"

char *ft_strrchr(const char *src, int c)
{
    const char *src1 = src;

    for (; *src != '\0'; src++);
    for (; src != src1; src--)
        if (*src == c)
            return ((char *)src);
    return ((*src == c) ? (char *)src : NULL);
}

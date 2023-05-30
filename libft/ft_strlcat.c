/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strlcat.c
*/

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i = 0;
    size_t length = 0;

    for (; dest[i] && i < size; i++);
    length = i;
    for (; src[i - length] && i < size - 1; i++)
        dest[i] = src[i - length];
    if (length < size)
        dest[i] = '\0';
    return (length + ft_strlen(src));
}

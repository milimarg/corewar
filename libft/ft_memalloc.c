/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memalloc.c
*/

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void *ft_memalloc(size_t size)
{
    char *s = malloc(size);

    if (s == NULL)
        return (NULL);
    else
        ft_bzero(s, size);
    return (s);
}

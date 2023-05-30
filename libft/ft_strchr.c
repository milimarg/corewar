/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strchr.c
*/

#include <string.h>
#include "libft.h"

char *ft_strchr(const char *src, int c)
{
    for (; *src != '\0'; src++)
        if (*src == c)
            return ((char *)src);
    if (*src == c)
        return ((char *)src);
    return (NULL);
}

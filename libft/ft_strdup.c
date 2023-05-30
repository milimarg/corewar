/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strdup.c
*/

#include "libft.h"

char *ft_strdup(char *src)
{
    char *dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    int i = 0;

    if (!dup)
        return (NULL);
    for (; src[i]; i++)
        dup[i] = src[i];
    dup[i] = '\0';
    return (dup);
}

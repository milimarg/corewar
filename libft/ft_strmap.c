/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strmap.c
*/

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char *ft_strmap(char const *s, char (*f)(char))
{
    unsigned int i = 0;
    char *dest = NULL;

    if (s == NULL || f == NULL)
        return (NULL);
    dest = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
    if (dest == NULL)
        return (NULL);
    while (*s && s != NULL)
        dest[i++] = f((char)*s++);
    dest[i] = '\0';
    return (dest);
}

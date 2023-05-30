/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strmapi.c
*/

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i = 0;
    char *dest = NULL;

    if (s == NULL || f == NULL)
        return (NULL);
    dest = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
    if (dest == NULL)
        return (NULL);
    for (; *s && s != NULL; i++)
        dest[i] = f(i, (char)*s++);
    dest[i] = '\0';
    return (dest);
}

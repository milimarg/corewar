/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strsub.c
*/

#include <stdlib.h>
#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *dest = NULL;
    size_t i = 0;

    if (s == NULL)
        return (NULL);
    if (start > (unsigned int)ft_strlen(s))
        return (NULL);
    if (*s == '\0' || s == NULL)
        return (NULL);
    dest = (char *)malloc(sizeof(*s) * (len + 1));
    if (dest == NULL)
        return (NULL);
    while (i < len && s[start])
        dest[i++] = s[start++];
    dest[i] = '\0';
    return (dest);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strtrim.c
*/

#include <stdlib.h>
#include "libft.h"

char *ft_strtrim(char const *s)
{
    char const *s_back = NULL;

    if (s == NULL)
        return (NULL);
    for (; *s == ' ' || *s == '\t' || *s == '\n'; s++);
    if (*s == '\0')
        return (ft_strnew(0));
    s_back = s + ft_strlen(s) - 1;
    for (; *s_back == ' ' || *s_back == '\t' || *s_back == '\n'; s_back--);
    return (ft_strsub(s, 0, s_back - s + 1));
}

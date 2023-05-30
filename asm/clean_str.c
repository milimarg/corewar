/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** clean_str.c
*/

#include "asm.h"

char *clean_str_end(char *str)
{
    int len = ft_strlen(str);

    for (; !char_is_visible(str[len]) && len >= 0; len--);
    str[len + 1] = '\0';
    return (str);
}

char *clean_str_start(char *str)
{
    char *new_str = NULL;
    int len = 0;

    for (; str[len] != '\0' && !char_is_visible(str[len]); len++);
    new_str = ft_strdup(&str[len]);
    return (new_str);
}

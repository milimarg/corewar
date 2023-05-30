/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strndup
*/

#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *dest = NULL;
    int i = 0;

    dest = malloc(sizeof(char) * (n + 1));
    for (; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

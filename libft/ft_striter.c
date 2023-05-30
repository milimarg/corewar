/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_striter.c
*/

#include <string.h>

void ft_striter(char *s, void (*f)(char*))
{
    if (s == NULL || f == NULL)
        return;
    while (*s && s != NULL)
        f(s++);
}

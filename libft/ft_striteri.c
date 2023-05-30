/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_striteri.c
*/

#include <string.h>

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i = 0;

    if (s == NULL || f == NULL)
        return;
    while (*s && s != NULL)
        f(i++, s++);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_putstr_fd.c
*/

#include "libft.h"

void ft_putstr_fd(char const *s, int fd)
{
    for (int i = 0; s[i] != '\0'; i++)
        ft_putchar_fd(s[i], fd);
}

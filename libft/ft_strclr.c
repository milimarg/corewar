/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strclr.c
*/

#include <string.h>

void ft_strclr(char *s)
{
    for (; s != NULL && *s; s++)
        *s = '\0';
}

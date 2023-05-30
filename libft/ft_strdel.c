/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strdel.c
*/

#include <stdlib.h>
#include <string.h>

void ft_strdel(char **as)
{
    if (as != NULL) {
        free(*as);
        *as = NULL;
    }
}

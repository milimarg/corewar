/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memdel.c
*/

#include <stdlib.h>

void ft_memdel(void **ap)
{
    free(*ap);
    *ap = NULL;
}

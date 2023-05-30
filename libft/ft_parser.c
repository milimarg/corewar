/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_parser.c
*/

#include "ft_print.h"

static void initialize_e_2(t_vars *e)
{
    e->printspace = 0;
    e->printlastspace = 0;
    e->printzero = 0;
    e->printprefix = 0;
    e->nb = NULL;
}

void ft_initialize_e(t_vars *e)
{
    e->align = 0;
    e->zero = 0;
    e->plus = 0;
    e->width = -1;
    e->pointlen = -1;
    e->percent = 0;
    e->neg = 0;
    e->f = -1;
    e->flags = 0;
    e->len = 0;
    e->type = -1;
    e->base = 10;
    e->printchar = 'E';
    e->printextra = 0;
    e->printminus = 0;
    e->printsign = '0';
    e->printlen = 0;
    e->hash = 0;
    e->printplus = 0;
    initialize_e_2(e);
}

void hash(t_vars *e)
{
    e->printprefix = TRUE;
    e->hash = TRUE;
}

int ft_findtype(char *str)
{
    int k = 0;
    char *types = "idDsScC%pUOXxou";

    for (; types[k] != '\0'; k++)
        if (types[k] == *str)
            return (k);
    return (-1);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_chars.c
*/

#include "ft_print.h"

int ft_putchar_count(char c)
{
    write(1, &c, 1);
    return (1);
}

void chars(char c, t_vars *e)
{
    e->printchar = (e->zero == TRUE) ? '0' : ' ';
    if (e->type == PERCENT) {
        if (e->width != -1 && e->align == FALSE)
            printspace(e->width - 1, e->printchar, e);
    } else if (e->width != -1 && e->align == FALSE)
        printspace(e->width - 1, ' ', e);
    e->totcount += ft_putchar_count(c);
    if (e->width != -1 && e->align == TRUE)
        printspace(e->width - 1, ' ', e);
}

void percent(t_vars *e)
{
    chars('%', e);
}

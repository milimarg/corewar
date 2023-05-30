/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_atoi_calc.c
*/

#include "libft.h"
#include <stdio.h>
#include "ft_print.h"

int ft_size_of_intmax(intmax_t nb, t_vars *e)
{
    int i = 0;

    if (nb == 0)
        return (1);
    if (nb < 0) {
        e->neg = 1;
        nb = -nb;
    }
    while (nb) {
        nb /= e->base;
        i++;
    }
    return (i);
}

int ft_size_of_uintmax(uintmax_t nb, t_vars *e)
{
    int i = 0;

    if (nb == 0)
        return (1);
    if (e->type == OCTAL || e->type == UOCTAL)
        e->base = 8;
    else if (e->type == HEX || e->type == UHEX || e->type == POINTER)
        e->base = 16;
    else
        e->base = 10;
    for (; nb; i++)
        nb /= e->base;
    return (i);
}

char *ft_atoi_uintmax(uintmax_t nb, t_vars *e)
{
    char *sixteen = NULL;
    int len = 0;

    if (nb == 0)
        return ("0");
    if (e->type == UHEX || e->type == UOCTAL)
        sixteen = "0123456789ABCDEF";
    else
        sixteen = "0123456789abcdef";
    e->nb = malloc(sizeof(char) * (e->len + 1));
    e->nb[e->len] = '\0';
    len = e->len;
    for (; nb; nb /= e->base)
        e->nb[--len] = sixteen[nb % e->base];
    return (e->nb);
}

char *ft_atoi_intmax(intmax_t nb, t_vars *e)
{
    char *sixteen = NULL;
    int len = 0;

    if (nb < -9223372036854775807)
        return ("9223372036854775808");
    if (nb == 0)
        return ("0");
    sixteen = "0123456789";
    e->nb = malloc(sizeof(char) * (e->len + 1));
    e->nb[e->len] = '\0';
    len = e->len;
    if (nb < 0)
        nb = -nb;
    while (nb) {
        e->nb[--len] = sixteen[nb % e->base];
        nb /= e->base;
    }
    return (e->nb);
}

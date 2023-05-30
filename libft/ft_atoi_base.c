/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_atoi_base.c
*/

#include <stdio.h>
#include "ft_print.h"

static void cutn(t_vars *e, char *str)
{
    if (str[0] == '0' && e->pointlen == 0)
        e->len = 0;
    if (e->plus && !e->neg)
        addsign('+', e);
    if (e->printspace && !e->plus && !e->neg)
        addsign(' ', e);
    if (e->neg)
        addsign('-', e);
}

void n_letter(intmax_t nb, t_vars *e)
{
    char *str = NULL;
    e->len = ft_size_of_intmax(nb, e);
    str = ft_atoi_intmax(nb, e);
    e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
    cutn(e, str);
    e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
    if ((e->printlen + e->printextra >= e->width || e->printchar == '0' ||
    e->align) && e->printextra)
        e->totcount += ft_putchar_count(e->printsign);
    if ((e->width > e->printextra + e->printlen) && !e->align)
        printspace(e->width - (e->printextra + e->printlen),
        e->printchar, e);
    if (e->printlen + e->printextra < e->width && e->printextra && !e->align
    && e->printchar != '0')
        e->totcount += ft_putchar_count(e->printsign);
    if (e->len < e->pointlen)
        printspace(e->pointlen - e->len, '0', e);
    if (!(e->pointlen == 0 && *str == '0'))
        e->totcount += ft_putstr_count(str);
    nb_post_flags(e);
}

static void printpointlen(t_vars *e, char *str)
{
    if (e->len < e->pointlen && (e->type == UHEX || e->type == HEX))
        printspace(e->pointlen - (e->len), '0', e);
    if (e->len < e->pointlen && (e->type == UUNSIGNED || e->type == UNSIGNED))
        printspace(e->pointlen - (e->len), '0', e);
    if (e->len < e->pointlen && (e->type == UOCTAL || e->type == OCTAL))
        printspace(e->pointlen - (e->len + e->printextra), '0', e);
    if (e->pointlen > 0 && (e->type == HEX || e->type == UHEX) && *str == '0')
        e->totcount += ft_putstr_count(str);
}

static void cutu(t_vars *e, char *str)
{
    e->printchar = (e->zero && e->pointlen == -1) ? '0' : ' ';
    calc_printextra(e);
    if (*str == '0' && e->pointlen == 0)
        e->len = 0;
    if (*str == '0' && e->pointlen == 0 && (e->type == OCTAL ||
    e->type == UOCTAL) && e->hash)
        e->len = 1;
    if (*str == '0' && e->type != POINTER) {
        e->printprefix = 0;
        e->printextra = 0;
    }
}

void u_letter(uintmax_t nb, t_vars *e)
{
    char *str = NULL;
    e->len = ft_size_of_uintmax(nb, e);
    str = ft_atoi_uintmax(nb, e);
    cutu(e, str);
    e->printlen = (e->len >= e->pointlen) ? e->len : e->pointlen;
    if ((e->printlen + e->printextra >= e->width || e->printchar == '0' ||
    e->align) && e->printextra > 0)
        ft_printprefix(e);
    if (e->printlen + e->printextra < e->width && !e->align)
        printspace(e->width - (e->printlen + e->printextra), e->printchar, e);
    if (e->printlen + e->printextra < e->width && !e->align &&
    e->printchar == ' ' && e->printextra)
        ft_printprefix(e);
    printpointlen(e, str);
    if (!(e->pointlen != -1 && *str == '0'))
        e->totcount += ft_putstr_count(str);
    if (e->pointlen != -1 && *str == '0' && (e->type == OCTAL ||
    e->type == UOCTAL) && e->hash)
        e->totcount += ft_putstr_count(str);
    nb_post_flags(e);
}

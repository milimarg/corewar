/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strings.c
*/

#include "ft_print.h"

int ft_putstr_count(char *str)
{
    int i = 0;

    if (!str)
        ft_putstr_count("(null)");
    else
        for (; *str; str++) {
            ft_putchar(*str);
            i++;
        }
    return (i);
}

void ft_putstr_cut(char *str, int width, t_vars *e)
{
    int i = 0;

    for (; i < width && *str; i++) {
        e->totcount += ft_putchar_count(*str);
        str++;
    }
}

static void check_str_with_cut(char *str, t_vars *e)
{
    if (e->width > e->printlen && e->align == TRUE) {
        ft_putstr_cut(str, e->printlen, e);
        printspace(e->width - e->printlen, ' ', e);
    } else if (e->width > e->printlen && e->align == FALSE) {
        printspace(e->width - e->printlen, ' ', e);
        ft_putstr_cut(str, e->printlen, e);
    }
}

void strings(char *str, t_vars *e)
{
    int len = 0;

    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (e->pointlen < len && e->pointlen != -1)
        e->printlen = e->pointlen;
    else
        e->printlen = len;
    if (e->width <= e->printlen)
        ft_putstr_cut(str, e->printlen, e);
    else
        check_str_with_cut(str, e);
}

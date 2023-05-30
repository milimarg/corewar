/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** main.c
*/

#include <stdarg.h>
#include "ft_print.h"

char *print_mainstring(char *str, t_vars *e)
{
    e->totcount += ft_putchar_count(*str);
    str++;
    return (str);
}

static int handle_flag(char **str, t_vars *e, va_list *ap)
{
    (*str)++;
    ft_initialize_e(e);
    *str = ft_printtype(*str, e);
    if (ft_error_handle(e))
        return (-1);
    typeformat(e);
    ftprint(*ap, e);
    if (e->nb)
        free(e->nb);
    e->nb = NULL;
    return (0);
}

int ft_printf(char *str, ...)
{
    va_list ap = {0};
    t_vars e = {0};

    e.totcount = 0;
    va_start(ap, str);
    while (*str != '\0') {
        if (*str != '%')
            str = print_mainstring(str, &e);
        if (*str == '%' && handle_flag(&str, &e, &ap) == -1)
            return (-1);
    }
    va_end(ap);
    return (e.totcount);
}

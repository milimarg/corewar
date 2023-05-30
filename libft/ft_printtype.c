/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_printtype.c
*/

#include "ft_print.h"

static void printtype_str_content_checker_3(char *str, t_vars *e)
{
    if ((*str == 'h' || *str == 'j' || *str == 'z' || *str == 'l') && !e->flags)
        e->flags = ft_flagconv(str);
    else if (ft_findtype(str) != -1)
        e->type = ft_findtype(str);
}

static void printtype_str_content_checker_2(char *str, t_vars *e)
{
    if (ft_isdigit(*str) == TRUE && *str != '0' && e->pointlen == -1
        && e->width == -1)
        e->width = ft_atoi(str);
    else if (*str == '.' && e->pointlen == -1)
        e->pointlen = ft_atoi(str + 1);
    else
        printtype_str_content_checker_3(str, e);
}

static void printtype_str_content_checker(char *str, t_vars *e)
{
    if (*str == '0' && e->pointlen == -1 && e->width == -1 && !e->zero)
        e->zero = TRUE;
    else if (*str == '#')
        hash(e);
    else
        printtype_str_content_checker_2(str, e);
}

char *ft_printtype(char *str, t_vars *e)
{
    for (; e->type == -1 && *str != '\0'; str++) {
        if (*str == '-')
            e->align = TRUE;
        if (*str == '+')
            e->plus = TRUE;
        if (*str == ' ')
            e->printspace = TRUE;
        if (*str != '-' && *str != '+' && *str != ' ')
            printtype_str_content_checker(str, e);
    }
    return (str);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_flagconv.c
*/

#include "ft_print.h"

static void flagconv_2(char *str, int *value)
{
    if (*str == 'l' && *(str + 1) == 'l')
        *value = 3;
    else if (*str == 'l')
        *value = 4;
    else
        *value = (*str == 'j') ? 5 : 6;
}

int ft_flagconv(char *str)
{
    int value = 0;

    if (*str == 'h' && *(str + 1) == 'h')
        value = 1;
    else if (*str == 'h')
        value = 2;
    else
        flagconv_2(str, &value);
    return (value);
}

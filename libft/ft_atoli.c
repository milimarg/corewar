/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_atoli.c
*/

#include "libft.h"

long ft_atoli(const char *str)
{
    long i = 0;
    long nb = 0;
    int is_neg = 0;

    for (; str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
        str[i] == '\v' || str[i] == '\f' || str[i] == '\r'; i++);
    if (str[i] == '-')
        is_neg = 1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return ((is_neg) ? -nb : nb);
}

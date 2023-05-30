/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_atoi.c
*/

#include "libft.h"

short ft_atoi_short(const char *s)
{
    int i = 0;
    short isneg = 1;
    short sum = 0;

    for (; s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
        s[i] == '\r' || s[i] == '\f'; i++);
    if (s[i] == '-')
        isneg = -isneg;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++) {
        sum = sum * 10;
        sum = sum + (s[i] - '0');
    }
    return (sum * isneg);
}

int ft_atoi(const char *s)
{
    int i = 0;
    int isneg = 1;
    int sum = 0;

    for (; s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
    s[i] == '\r' || s[i] == '\f'; i++);
    if (s[i] == '-')
        isneg = -isneg;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (; s[i] != '\0' && s[i] >= '0' && s[i] <= '9'; i++) {
        sum = sum * 10;
        sum = sum + (s[i] - '0');
    }
    return (sum * isneg);
}

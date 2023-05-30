/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_atoi_long.c
*/

#include "libft.h"

long long ft_atoi_long(const char *s)
{
    int i = 0;
    int isneg = 1;
    long long sum = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
    s[i] == '\r' || s[i] == '\f')
        i++;
    if (s[i] == '-')
        isneg = -isneg;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        sum = sum * 10;
        sum = sum + (s[i] - '0');
        i++;
    }
    return ((i > 19) ? 2147483649 : (sum * isneg));
}

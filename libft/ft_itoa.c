/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_itoa.c
*/

#include <stdlib.h>
#include "libft.h"

static int ft_itoa_length(int n)
{
    int i = 1;
    int neg = 0;

    if (n < 0) {
        n = -n;
        neg = 1;
    }
    for (; n > 9; i++)
        n = n / 10;
    return (i + neg + 1);
}

char *ft_itoa(int n)
{
    char *str = NULL;
    int length = 0;
    int neg = 0;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    length = ft_itoa_length(n);
    str = (char*)malloc(sizeof(*str) * (length));
    if (str == NULL)
        return (NULL);
    str[--length] = '\0';
    if (n < 0) {
        n = -n;
        neg = 1;
    }
    for (; length--; n /= 10)
        str[length] = (n % 10) + '0';
    str[0] = (neg) ? '-' : str[0];
    return (str);
}

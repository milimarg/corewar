/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_memcmp.c
*/

#include <string.h>

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    unsigned char *str1t = (unsigned char *)str1;
    unsigned char *str2t = (unsigned char *)str2;

    for (size_t i = 0; i < n; i++)
        if (str1t[i] != str2t[i])
            return (str1t[i] - str2t[i]);
    return (0);
}

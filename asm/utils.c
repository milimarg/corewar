/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** utils.c
*/

#include "asm.h"

int reverse_int(int n)
{
    int reversed_n =
            ((n & 0x000000FF) << 24) |
            ((n & 0x0000FF00) << 8) |
            ((n & 0x00FF0000) >> 8) |
            ((n & 0xFF000000) >> 24);
    return (reversed_n);
}

short reverse_short(short n)
{
    short reversed_n =
            ((n) & 0xFF) << 8 |
            ((n & 0xFF00) >> 8);
    return (reversed_n);
}

int is_str_alpha(const char *s)
{
    for (const char *temp = s; *temp != '\0'; temp++)
        if (!char_is_alpha(*temp))
            return (0);
    return (1);
}

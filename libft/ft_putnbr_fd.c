/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_putnbr_fd.c
*/

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    unsigned int b = 0;

    if (n < 0) {
        ft_putchar_fd('-', fd);
        b = -n;
    } else
        b = n;
    if (b < 10)
        ft_putchar_fd((b + '0'), fd);
    else {
        ft_putnbr_fd(b / 10, fd);
        ft_putchar_fd(b % 10 + '0', fd);
    }
}

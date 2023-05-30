/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_tolower.c
*/

int ft_tolower(int c)
{
    return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

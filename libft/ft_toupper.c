/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_toupper.c
*/

int ft_toupper(int c)
{
    return ((c >= 'a' && c <= 'z') ? c - 32 : c);
}

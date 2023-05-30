/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strstrlen.c
*/

int ft_strstrlen(char **str)
{
    int len = 0;

    for (; str[len] != 0; len++);
    return (len);
}

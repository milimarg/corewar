/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strlen.c
*/

int ft_strlen(char const *s)
{
    int i = 0;

    for (; s[i] != '\0'; i++);
    return (i);
}

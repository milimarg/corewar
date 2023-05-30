/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** parsing_second.c
*/

#include "vm.h"

/*
** In this .c file, we are going to parse the data + check for errors
** We to get:
**         - COREWAR_EXEC_MAGIC
**        - Name of the .cor
**        - Comments
**        - Instructions
*/

void ft_add_player_name(t_env *e, int k)
{
    char *dest = e->player[k].name;
    char *src = e->player[k].string;
    int i = 0;

    for (; i < PROG_NAME_LENGTH; i++)
        dest[i] = src[i + 4];
    while (i <= PROG_NAME_LENGTH)
        dest[i++] = '\0';
    dest[PROG_NAME_LENGTH] = '\0';
}

void ft_add_player_comment(t_env *e, int k)
{
    char *dest = e->player[k].comment;
    char *src = e->player[k].string;
    int i = 0;

    for (; i < COMMENT_LENGTH; i++)
        dest[i] = src[i + PROG_NAME_LENGTH + 12];
    while (i <= COMMENT_LENGTH)
        dest[i++] = '\0';
    dest[COMMENT_LENGTH] = '\0';
}

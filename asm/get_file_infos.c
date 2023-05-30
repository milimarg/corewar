/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** get_file_infos.c
*/

#include <stdio.h>
#include "asm.h"

static void get_value_between_quotes_header(char *buffer, asm_t *env,
int comment_or_name)
{
    const char quote = '"';
    int i = 0;
    int len = 0;

    for (; buffer[i] != '\0' && buffer[i] != quote; i++);
    i++;
    for (; buffer[i + len] != '\0' && buffer[i + len] != quote; len++);

    if (comment_or_name) {
        for (int j = 0; j < len; j++)
            env->header.prog_name[j] = buffer[i + j];
        ft_memset(&env->header.prog_name[len], 0, PROG_NAME_LENGTH - len + 1);
        env->prog_name_len = len;
    } else {
        for (int j = 0; j < len; j++)
            env->header.comment[j] = buffer[i + j];
        ft_memset(&env->header.comment[len], 0, COMMENT_LENGTH - len + 1);
        env->prog_comment_len = len;
    }
}

static int check_if_quotes_in_header(char *buffer)
{
    int quotes_nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '"')
            quotes_nb++;
    }
    if (quotes_nb != 2)
        write(2, "asm: quotes number is not 2\n", 28);
    return (quotes_nb == 2);
}

int get_champion_name(char *buffer, asm_t *env)
{
    if (ft_strncmp(buffer, NAME_CMD_STRING, env->name_cmd_len) == 0) {
        if (!env->found_name && !check_if_quotes_in_header(buffer))
            return (84);
        if (!env->found_name) {
            env->found_name = 1;
            get_value_between_quotes_header(buffer, env, 1);
        } else {
            write(2, "asm: champion's name already declared\n", 38);
        }
    }
    return (0);
}

int get_champion_comment(char *buffer, asm_t *env)
{
    if (ft_strncmp(buffer, COMMENT_CMD_STRING, env->name_cmd_len) == 0) {
        if (!env->found_comment && !check_if_quotes_in_header(buffer))
            return (84);
        if (!env->found_comment) {
            env->found_comment = 1;
            get_value_between_quotes_header(buffer, env, 0);
        } else {
            write(2, "asm: champion's comment already declared\n", 41);
        }
    }
    return (0);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** init_env.c
*/

#include "asm.h"

static int get_champion_infos(FILE **fd, char *filename, asm_t *env)
{
    char *buffer = NULL;
    char *clean_buffer = NULL;
    size_t s = 0;

    while (getline(&buffer, &s, *fd) != -1) {
        clean_buffer = clean_str_start(buffer);
        if (get_champion_name(clean_buffer, env) == 84
            || env->prog_name_len > PROG_NAME_LENGTH)
            return (84);
        if (get_champion_comment(clean_buffer, env) == 84
            || env->prog_comment_len > COMMENT_LENGTH)
            return (84);
        free(clean_buffer);
    }
    fclose(*fd);
    *fd = fopen(filename, "r");
    return (0);
}

int init_env(asm_t *env, FILE **fd, char *filename)
{
    env->infos = malloc(sizeof(infos_t));
    env->found_name = 0;
    env->found_comment = 0;
    env->header.magic = reverse_int(COREWAR_EXEC_MAGIC);
    env->header.prog_size = 0;
    env->name_cmd_len = ft_strlen(NAME_CMD_STRING);
    env->comment_cmd_len = ft_strlen(COMMENT_CMD_STRING);
    env->labels_nb = 0;
    env->label_list = NULL;
    if (get_champion_infos(fd, filename, env) == 84)
        return (84);
    return (0);
}

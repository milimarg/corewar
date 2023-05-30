/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** asm.c
*/

#include <stdio.h>
#include <unistd.h>
#include "asm.h"

static int write_in_file(char *output, asm_t *env)
{
    if (!env->found_name || !env->found_comment) {
        write(2, "asm: champion's name or comment missing\n", 40);
        return (84);
    }
    env->output_fd = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (env->output_fd == -1) {
        write(2, "asm: output_fd not found\n", 25);
        return (84);
    }
    write_data_in_file(env, 0);
    write_data_in_file(env, 1);
    close(env->output_fd);
    return (0);
}

static int manipulate_string(char *buffer, asm_t *env, int *line_pos)
{
    char *clean_buffer = clean_str_start(buffer);

    if (clean_buffer[0] == '\0' ||
        !ft_strncmp(clean_buffer, NAME_CMD_STRING, env->prog_name_len) ||
        !ft_strncmp(clean_buffer, COMMENT_CMD_STRING, env->comment_cmd_len))
        return (1);
    if (env->found_name && env->found_comment)
        get_live(clean_buffer, env);
    get_labels_nb(env, clean_buffer, *line_pos);
    free(clean_buffer);
    (*line_pos)++;
    return (0);
}

static int parser_asm(FILE *fd, asm_t *env, char *output, char *filename)
{
    char *buffer = NULL;
    size_t s = 0;
    int line_pos = 0;

    if (init_env(env, &fd, filename) == 84)
        return (84);
    while (getline(&buffer, &s, fd) != -1) {
        if (manipulate_string(buffer, env, &line_pos))
            continue;
    }
    detect_label_in_buffer(env);
    if (write_in_file(output, env) == 84)
        return (84);
    if (error_handling(env) == 84)
        return 84;
    return (0);
}

int main(int argc, char **argv)
{
    char *output_filepath = NULL;
    FILE *fd = NULL;
    asm_t env = {0};

    if (argc != 2)
        return (84);
    fd = fopen(argv[1], "r");
    if (fd == NULL) {
        write(2, "asm: file cannot be opened\n", 27);
        return (84);
    }
    output_filepath = get_output_filename(argv[1]);
    if (output_filepath == NULL) {
        write(2, "asm: wrong file extension\n", 26);
        return (84);
    }
    if (parser_asm(fd, &env, output_filepath, argv[1]) == 84)
        return (84);
    fclose(fd);
    return (0);
}

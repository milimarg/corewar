/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** write_data_in_file.c
*/

#include <stdio.h>
#include "asm.h"

static int write_op_code(asm_t *env, char *instruction,
int get_prog_size_or_write)
{
    int i = 0;
    int found = 0;
    char op = 0;

    for (; op_tab[i].mnemonique != 0 && !found; i++)
        if (!ft_strcmp(op_tab[i].mnemonique, instruction))
            found = 1;
    if (!found) {
        write(2, "asm: op_code not found\n", 23);
        return (84);
    }
    op = (char)i;
    if (!get_prog_size_or_write)
        env->header.prog_size += sizeof(op);
    else
        write(env->output_fd, &op, sizeof(op));
    return (0);
}

static void write_coding_byte(infos_t *copy, asm_t *env,
int get_prog_size_or_write)
{
    char coding_byte = 0b00000000;

    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (!ft_strcmp(op_tab[i].mnemonique, get_cmd(copy)) &&
        op_tab[i].nbr_args == 1 && ft_strcmp("aff", get_cmd(copy)) != 0)
            return;
    for (int i = 0; i < 4; i++) {
        coding_byte <<= 2;
        coding_byte |= copy->types[i];
    }
    if (!get_prog_size_or_write)
        env->header.prog_size += sizeof(coding_byte);
    else
        write(env->output_fd, &coding_byte, sizeof(coding_byte));
}

static int write_parameter(infos_t *copy, int get_prog_size_or_write,
asm_t *env)
{
    int (*write_function[3])(int, asm_t *, infos_t *, int) = {&write_register,
    &write_direct, &write_indirect};

    for (int i = 0; copy->array[i] != NULL; i++) {
        if (copy->types[i] == OTHERWISE)
            continue;
        if (write_function[copy->types[i] - 1](get_prog_size_or_write, env,
        copy, i) == 84)
            return (84);
    }
    return (0);
}

static void write_header(asm_t *env)
{
    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next)
        for (int i = 0; i < temp->distances_nb; i++)
            env->header.prog_size += sizeof(temp->distances[i]);
    env->header.prog_size = reverse_int(env->header.prog_size);
    write(env->output_fd, &env->header, sizeof(env->header));
}

int write_data_in_file(asm_t *env, int get_prog_size_or_write)
{
    if (get_prog_size_or_write)
        write_header(env);
    for (infos_t *copy = env->infos->next; copy != NULL; copy = copy->next) {
        if (write_op_code(env, get_cmd(copy), get_prog_size_or_write) == 84)
            return (84);
        write_coding_byte(copy, env, get_prog_size_or_write);
        if (write_parameter(copy, get_prog_size_or_write, env) == 84)
            return (84);
    }
    return (0);
}

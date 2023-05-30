/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** write_data_exceptions.c
*/

#include "asm.h"

void write_data_exceptions(infos_t *copy, int i, int get_prog_size_or_write,
asm_t *env)
{
    int label = ft_atoi(copy->array[i]);

    label = reverse_int(label);
    if (!get_prog_size_or_write)
        env->header.prog_size += sizeof(short);
    else
        write(env->output_fd, &label, sizeof(label));
}

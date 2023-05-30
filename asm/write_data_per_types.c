/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** write_data_per_types.c
*/

#include "asm.h"

int write_register(int get_prog_size_or_write, asm_t *env, infos_t *copy, int i)
{
    char register_nb = (char)ft_atoi(copy->array[i]);

    if (is_register_valid(register_nb)) {
        if (!get_prog_size_or_write)
            env->header.prog_size += sizeof(register_nb);
        else
            write(env->output_fd, &register_nb, sizeof(register_nb));
    } else {
        write(2, "asm: register number is out of range\n", 37);
        return (84);
    }
    return (0);
}

static void get_labels_value(asm_t *env, char *arg, short *label)
{
    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next) {
        if (!ft_strcmp(&arg[1], temp->name)) {
            *label = temp->distances[temp->index++];
            temp->index = (temp->index >= temp->distances_nb) ? 0 : temp->index;
            return;
        }
    }
}

static int check_exceptions_mnemonique(infos_t *copy, int i,
int get_prog_size_or_write, asm_t *env)
{
    char *mnemonique_to_check[] = {"live", "ld", NULL};

    for (int j = 0; mnemonique_to_check[j] != NULL; j++) {
        if (!ft_strcmp(op_tab[copy->op_tab_index].mnemonique,
        mnemonique_to_check[j])) {
            write_data_exceptions(copy, i, get_prog_size_or_write, env);
            return (1);
        }
    }
    return (0);
}

int write_direct(int get_prog_size_or_write, asm_t *env, infos_t *copy, int i)
{
    short label = 0;
    char *arg = copy->array[i];

    if (arg[0] == LABEL_CHAR && is_str_alpha(&arg[1]))
        get_labels_value(env, arg, &label);
    else {
        if (check_exceptions_mnemonique(copy, i, get_prog_size_or_write, env))
            return (0);
        label = (short)ft_atoi(arg);
    }
    label = reverse_short(label);
    if (!get_prog_size_or_write)
        env->header.prog_size += sizeof(label);
    else
        write(env->output_fd, &label, sizeof(label));
    return (0);
}

int write_indirect(int get_prog_size_or_write, asm_t *env, infos_t *copy, int i)
{
    int label = ft_atoi(copy->array[i]);

    label = reverse_int(label);
    if (!get_prog_size_or_write)
        env->header.prog_size += sizeof(label);
    else
        write(env->output_fd, &label, sizeof(label));
    return (0);
}

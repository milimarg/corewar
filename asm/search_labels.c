/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** search_labels.c
*/

#include "asm.h"

static void get_all_sizes_for_label(int *index, infos_t *temp, label_t *label,
short *size)
{
    int j = 0;

    if (*index == 0) {
        for (; temp->array[j] != NULL &&
        ft_strcmp(&temp->array[j][1], label->name) != 0; j++);
        for (; temp->array[j] != NULL; j++)
            *size += get_size_of_parameter(temp, j);
    } else {
        *size += get_instruction_weight(temp);
        for (int z = 0; temp->array[z] != NULL; z++)
            *size += get_size_of_parameter(temp, z);
    }
    (*index)++;
}

static void check_instructions_for_label(int pos[2], asm_t *env, label_t *label,
int before_or_after)
{
    int line_pos_start = pos[0];
    int line_pos_end = pos[1];
    int shift = 0;
    int index = 0;
    infos_t *temp = env->infos;
    short size = 0;

    for (; shift < line_pos_start; temp = temp->next)
        shift++;
    for (; shift < line_pos_end + 1; temp = temp->next) {
        if (temp->array == NULL)
            continue;
        get_all_sizes_for_label(&index, temp, label, &size);
        shift++;
    }
    label->distances[label->index++] = (!before_or_after) ? size : size * -1;
}

static void detect_instruction_for_label(asm_t *env, infos_t *copy, int i,
int line)
{
    int start_pos = 0;
    int end_pos = 0;

    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next) {
        if (!ft_strcmp(&copy->array[i][1], temp->name)) {
            start_pos = (line < i) ? line : temp->line_pos;
            end_pos = (line < i) ? temp->line_pos : line;
            check_instructions_for_label((int[2]){start_pos, end_pos}, env,
            temp, (line >= i));
        }
    }
}

static void get_labels_called_nb(asm_t *env, infos_t *copy, int i)
{
    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next)
        if (!ft_strcmp(&copy->array[i][1], temp->name))
            temp->distances_nb++;
}

void detect_label_in_buffer(asm_t *env)
{
    int line_pos = 0;

    for (infos_t *copy = env->infos->next; copy != NULL; copy = copy->next)
        for (int i = 0; copy->array[i] != NULL; i++)
            get_labels_called_nb(env, copy, i);
    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next) {
        temp->distances = malloc(sizeof(short) * temp->distances_nb);
        for (int i = 0; i < temp->distances_nb; i++)
            temp->distances[i] = 0;
    }
    for (infos_t *copy = env->infos->next; copy != NULL; copy = copy->next) {
        for (int i = 0; copy->array[i] != NULL; i++)
            detect_instruction_for_label(env, copy, i, line_pos);
        line_pos++;
    }
    for (label_t *temp = env->label_list; temp != NULL; temp = temp->next)
        temp->index = 0;
}

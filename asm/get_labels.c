/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** labels.c
*/

#include "asm.h"

static char *cut_label_name(char *buffer)
{
    int i = 0;

    for (; char_is_alpha(buffer[i]); i++);
    return (my_strndup(buffer, i));
}

static void add_label_to_list(asm_t *env, char *buffer, int line_pos)
{
    label_t *temp = NULL;
    label_t *label = malloc(sizeof(label_t));

    label->name = cut_label_name(buffer);
    label->line_pos = line_pos;
    label->distances = NULL;
    label->distances_nb = 0;
    label->index = 0;
    label->next = NULL;
    if (env->label_list == NULL) {
        env->label_list = label;
    } else {
        for (temp = env->label_list; temp->next != NULL; temp = temp->next);
        temp->next = label;
    }
}

void get_labels_nb(asm_t *env, char *buffer, int line_pos)
{
    int i = 0;

    for (; char_is_alpha(buffer[i]) && buffer[i] != '\0'; i++);
    if (buffer[i] == '\0')
        return;
    if (buffer[i] == LABEL_CHAR) {
        env->labels_nb++;
        add_label_to_list(env, buffer, line_pos);
    }
}

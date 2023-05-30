/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** add_to_list
*/

#include "./asm.h"

void add_to_list(infos_t **head, int indx, char **values, param_type_t *types)
{
    infos_t *copy = NULL;
    infos_t *node = malloc(sizeof(infos_t));

    node->op_tab_index = indx;
    node->array = values;
    node->types = types;
    node->next = NULL;
    if (*head == NULL)
        *head = node;
    else {
        for (copy = *head; copy->next != NULL; copy = copy->next);
        copy->next = node;
    }
}

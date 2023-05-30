/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** get_infos_for_labels.c
*/

#include "asm.h"

short get_size_of_parameter(infos_t *node, int index)
{
    short size = 0;

    if (node == NULL) {
        write(2, "asm: cannot get size of NULL parameter\n", 39);
        return (size);
    }
    switch (node->types[index]) {
        case REGISTER:
            size = T_REG;
            break;
        case DIRECT:
            size = T_DIR;
            break;
        case INDIRECT:
            size = T_IND;
            break;
        case OTHERWISE:
            break;
    }
    return (size);
}

short get_instruction_weight(infos_t *copy)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (!ft_strcmp(op_tab[i].mnemonique,
            op_tab[copy->op_tab_index].mnemonique) &&
            op_tab[i].nbr_args == 1 && ft_strcmp("aff",
            op_tab[copy->op_tab_index].mnemonique) != 0)
            return (1);
    }
    return (2);
}

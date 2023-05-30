/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** check_errors
*/

#include "./asm.h"

int get_arg_type(param_type_t *tab)
{
    int lol = 0;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        lol = tab[i] != OTHERWISE ? lol + 1 : lol;
    return lol;
}

int choose_right(int type_or, int type_ch)
{
    int direct = 0;
    int indirect = 0;
    int reggister = 0;
    direct = type_or & T_DIR ? direct + 1 : 0;
    indirect = type_or & T_IND ? indirect + 1 : 0;
    reggister = type_or & T_REG ? reggister + 1 : 0;
    direct = type_ch == DIRECT ? direct + 1 : 0;
    indirect = type_ch == INDIRECT ? indirect + 1 : 0;
    reggister = type_ch == REGISTER ? reggister + 1 : 0;
    if (direct == 2 || indirect == 2 || reggister == 2)
        return 0;
    return 1;
}

int error_handling(asm_t *env)
{
    int to_check = 0;

    for (infos_t *copy = env->infos->next; copy != NULL; copy = copy->next) {
        to_check = 0;
        if (get_arg_type(copy->types) != op_tab[copy->op_tab_index].nbr_args)
            return 84;
        for (int i = 0; i < op_tab[copy->op_tab_index].nbr_args &&
                to_check != 1; i++)
            to_check = choose_right(op_tab[copy->op_tab_index].type[i],
                copy->types[i]);
        if (to_check == 1)
            return 84;
    }
    return 0;
}

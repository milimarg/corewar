/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** save_string_per_types.c
*/

#include "asm.h"

void save_register(param_type_t *tab, int i, asm_t *env)
{
    tab[i] = REGISTER;
    env->cmd_value[i] = ft_strdup(&env->cmd_value[i][1]);
}

void save_direct(param_type_t *tab, int i, asm_t *env)
{
    tab[i] = DIRECT;
    env->cmd_value[i] = ft_strdup(&env->cmd_value[i][1]);
}

void save_indirect(param_type_t *tab, int i, asm_t *env)
{
    tab[i] = INDIRECT;
    env->cmd_value[i] = ft_strdup(env->cmd_value[i]);
}

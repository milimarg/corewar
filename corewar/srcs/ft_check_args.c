/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_check_args.c
*/

#include "vm.h"

/*
** Clearly, this function check if the args of the acb are correct
**
** If the last to digit are not blank => error
** Get the number of args and check if it's the one we were waiting for.
** Check if each args are valid
**
** We'll have to figure out how we handle the errors and what to do with the
** data that we get
*/

int ft_check_args_2(t_env e, t_cursor cursor, int nb_of_args)
{
    int opcode = ZMASK(e.a[cursor.index].hex);
    char acb = e.a[cursor.index + 1].hex;

    for (int i = 0; i < nb_of_args; i++) {
        if ((acb >> (6 - i * 2) & 0x3) == REG_CODE &&
        (e.op_tab[opcode].params_type[i] & T_REG) == T_REG)
            continue;
        if ((acb >> (6 - i * 2) & 0x3) == DIR_CODE &&
        (e.op_tab[opcode].params_type[i] & T_DIR) == T_DIR)
            continue;
        if ((acb >> (6 - i * 2) & 0x3) == IND_CODE &&
        (e.op_tab[opcode].params_type[i] & T_IND) == T_IND)
            continue;
        return (0);
    }
    return (1);
}

int ft_check_args(t_env e, t_cursor cursor)
{
    int opcode = ZMASK(e.a[cursor.index].hex);

    if (opcode < 1 || opcode > 16)
        return (0);
    if (e.op_tab[opcode].acb == 0)
        return (1);
    if (ft_check_args_2(e, cursor, e.op_tab[opcode].nb_params) == 1)
        return (1);
    else {
        return (0);
    }
}

int ft_count_jump(int type, int label_size)
{
    if (type == REG_CODE)
        return (1);
    if (type == DIR_CODE)
        return (2 + 2 * (1 - label_size));
    if (type == IND_CODE)
        return (2);
    return (0);
}

int ft_jump_acb(t_env *e, int opcode, int acb)
{
    int jump = 0;
    int count = 0;

    if (opcode < 1 || opcode > 16)
        return (1);
    count = e->op_tab[opcode].nb_params;
    jump += ft_count_jump((acb >> 6) & 3, e->op_tab[opcode].label_size);
    if (count > 1)
        jump += ft_count_jump((acb >> 4) & 3, e->op_tab[opcode].label_size);
    if (count > 2)
        jump += ft_count_jump((acb >> 2) & 3, e->op_tab[opcode].label_size);
    return (jump + 2);
}

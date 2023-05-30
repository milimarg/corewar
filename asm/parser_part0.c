/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** parser_part0
*/

#include <stdio.h>
#include "./asm.h"

static void set_values(asm_t *env, int index, param_type_t *tab)
{
    int i = 0;

    for (i = 0; env->cmd_value[i] != NULL; i++) {
        if (env->cmd_value[i][0] == 'r') {
            save_register(tab, i, env);
            continue;
        }
        if (env->cmd_value[i][0] == DIRECT_CHAR) {
            save_direct(tab, i, env);
            continue;
        }
        if (char_is_number(env->cmd_value[i][0])) {
            save_indirect(tab, i, env);
            continue;
        }
        tab[i] = OTHERWISE;
    }
    ft_memset(&tab[i], OTHERWISE, 4 - i);
    add_to_list(&env->infos, index, env->cmd_value, tab);
}

static char **value_in_array(char *str)
{
    char **array = my_str_to_word_array(str);
    for (int i = 0; array[i] != NULL; i++) {
        array[i] = clean_str_start(array[i]);
    }
    return array;
}

static void get_live_sec(char *tmp2, char *tmp, int i, asm_t *env)
{
    param_type_t *tab = NULL;

    if (tmp2 != NULL) {
        env->cmd_value = value_in_array(tmp2);
        free(tmp2);
        env->index_value = i;
        tab = malloc(sizeof(param_type_t) * MAX_ARGS_NUMBER);
        set_values(env, i, tab);
    } else
        free(tmp);
}

static char *restr(char *tmp, int *i)
{
    char *tmp3 = NULL;

    for (*i = 0; op_tab[*i].mnemonique != 0; i++) {
        tmp3 = ft_strstr(tmp, op_tab[*i].mnemonique);
        if (tmp3 != NULL) {
            tmp3 = ft_strdup(&tmp3[ft_strlen(op_tab[*i].mnemonique)]);
            tmp3 = tmp3[0] == LABEL_CHAR ? restr(tmp3, i) : tmp3;
            free(tmp);
            return (tmp3);
        }
    }
    return (tmp);
}

void get_live(char *buffer, asm_t *env)
{
    char *tmp = NULL;
    char *tmp2 = NULL;
    int i = 0;
    int ok = 0;

    for (i = 0; op_tab[i].mnemonique != 0; i++) {
        ok = 0;
        tmp = ft_strstr(buffer, op_tab[i].mnemonique);
        if (tmp != NULL) {
            tmp = ft_strdup(&tmp[ft_strlen(op_tab[i].mnemonique)]);
            tmp = tmp[0] == LABEL_CHAR ? restr(tmp, &i) : tmp;
            ok = tmp[0] != ' ' && tmp[0] != '\t' ? 0 : 1;
            tmp2 = clean_str_start(tmp);
            tmp2 = clean_str_end(tmp2);
            free(tmp);
        } if (ok == 1)
            break;
    }
    get_live_sec(tmp2, tmp2, i, env);
}

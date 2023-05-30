/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_live.c
*/

#include "../srcs/vm.h"

int ft_live_match(t_env *e, int player_id)
{
    for (int i = 0; i < e->player_amount; i++)
        if (e->player[i].nbr == player_id)
            return (i);
    return (-1);
}

void ft_live(t_env *e, t_cursor *cursor)
{
    int player_id = get_dir(e, cursor, 1, 4);
    int player_pos = ft_live_match(e, player_id);

    if (player_pos > -1) {
        e->lives += 1;
        cursor->life = 1;
        e->player[player_pos].live += 1;
        ft_printf("Le joueur %d (%s) est en vie.\n", e->player[player_pos].nbr,
        e->player[player_pos].name);
        e->winner = player_pos;
        ft_update_cursor(e, cursor, 5);
    } else
        ft_update_cursor(e, cursor, 5);
}

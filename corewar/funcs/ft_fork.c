/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_fork.c
*/

#include "../srcs/vm.h"

void ft_clone_cursor_reg(int *dest, int *src)
{
    for (int i = -1; ++i < REG_NUMBER; )
        dest[i] = src[i];
}

t_cursor *ft_clone_cursor(t_cursor *cursor, t_cursor *fork_cursor)
{
    fork_cursor = malloc(sizeof(t_cursor));
    if (fork_cursor == NULL)
        return (NULL);
    fork_cursor->counter = 0;
    fork_cursor->player = cursor->player;
    fork_cursor->carry = cursor->carry;
    fork_cursor->cycle = 1;
    fork_cursor->life = cursor->life;
    fork_cursor->dead = cursor->dead;
    fork_cursor->color = cursor->color;
    ft_clone_cursor_reg(fork_cursor->reg, cursor->reg);
    fork_cursor->running = 0;
    fork_cursor->index = cursor->index;
    fork_cursor->next = NULL;
    fork_cursor->prev = NULL;
    return (fork_cursor);
}

void ft_fork_both(t_env *e, t_cursor *cursor, int lfork)
{
    t_cursor *fork_cursor = ft_clone_cursor(cursor, NULL);
    t_cursor *head_temp = e->head->prev;
    t_cursor *temp = head_temp->prev;
    int index_extra = get_dir(e, cursor, 1, 2);

    head_temp->prev = fork_cursor;
    fork_cursor->prev = temp;
    temp->next = fork_cursor;
    fork_cursor->next = head_temp;
    e->cursors += 1;
    ft_update_cursor(e, cursor, 3);
    if (lfork)
        ft_update_cursor(e, fork_cursor, MODA(index_extra));
    else
        ft_update_cursor(e, fork_cursor, MODX(index_extra));
}

void ft_fork(t_env *e, t_cursor *cursor)
{
    ft_fork_both(e, cursor, 0);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** init_cursors.c
*/

#include "vm.h"

t_cursor    *ft_create_cursor(int i, t_env *e)
{
    t_cursor *newcursor = malloc(sizeof(t_cursor));

    if (newcursor == NULL)
        return (NULL);
    newcursor->counter = 0;
    newcursor->player = i;
    newcursor->life = 0;
    newcursor->dead = 0;
    newcursor->carry = 0;
    newcursor->cycle = 0;
    init_reg(newcursor);
    newcursor->reg[0] = e->player[i].nbr;
    newcursor->color = (1 + i % 6) + 6;
    newcursor->running = 0;
    newcursor->index = e->player[i].index_start;
    newcursor->next = NULL;
    newcursor->prev = NULL;
    return (newcursor);
}

t_cursor *ft_add_cursor_to_stack(t_env *e, t_cursor *stack, int i)
{
    while (stack && stack->next)
        stack = stack->next;
    stack->next = ft_create_cursor(i, e);
    stack->next->prev = stack;
    return (stack);
}

t_cursor *ft_create_cursor_list(t_env *e)
{
    t_cursor *stack = NULL;
    t_cursor *head = NULL;

    for (int i = e->player_amount - 1; i > -1; i--) {
        if (!stack) {
            stack = ft_create_cursor(i, e);
            head = stack;
        } else
            stack = ft_add_cursor_to_stack(e, stack, i);
    }
    return (head);
}

void init_color_cursor(t_env *e)
{
    for (t_cursor *cursor = e->head; !cursor->counter; cursor = cursor->next) {
        ft_update_cursor(e, cursor, 0);
    }
}

void ft_init_cursor(t_env *e)
{
    t_cursor *stack = ft_create_cursor_list(e);

    e->head = stack;
    for (; stack && stack->next; stack = stack->next);
    stack->next = ft_create_cursor(0, e);
    stack->next->counter = 1;
    stack->next->next = e->head;
    stack->next->prev = stack;
    e->head->prev = stack->next;
    init_color_cursor(e);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** move_cursors.c
*/

#include "vm.h"

void ft_update_cursor(t_env *e, t_cursor *cursor, int i)
{
    int index_temp = cursor->index;

    if (e->a[cursor->index].occupied > 0)
        e->a[cursor->index].occupied -= 1;
    cursor->index += i;
    cursor->index = MODA(cursor->index);
    e->a[cursor->index].color = cursor->color;
    e->a[cursor->index].occupied += 1;
    if (e->a[index_temp].occupied == 0)
        e->a[index_temp].color = e->a[index_temp].prevcolor;
}

static void move_cursor_in_linked_list(t_env *e, t_cursor *cursor, int *end)
{
    static void (*functions[2])(t_env *, t_cursor *) = {&ft_add_cycle,
    &ft_cycle_end_and_execute};

    if (cursor->counter)
        ft_adjust_cycle_macro(e, cursor, end);
    else {
        if (!cursor->dead) {
            functions[cursor->running](e, cursor);
        }
    }
}

void ft_move_cursors(t_env *e)
{
    int end = 1;
    t_cursor *cursor = e->head;

    if (e->bonus_2d)
        ft_init_ncurses();
    ft_print_arena(e);
    while (end) {
        move_cursor_in_linked_list(e, cursor, &end);
        cursor = cursor->next;
    }
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_print_arena.c
*/

#include "vm.h"

void ft_print_game_stats(t_env *e)
{
    int i = -1;

    while (++i < e->player_amount)
        ft_print_lives(e, i);
    attron(COLOR_PAIR(14));
    printw("\n\nCycle: %-10d Cursors: %-10d Total Number of lives: %d/%-10d \
    Checks: %d/9 > Decrease cycle to die with: %d     \
    Cycles to die: %d/%d\n\n", e->tot_cycle, e->cursors, NBR_LIVE, e->lives, \
    e->check, CYCLE_DELTA, e->cycles_to_die, e->cycle);
    attroff(COLOR_PAIR(14));
    refresh();
}

void ft_print_bonus(t_env *e)
{
    int i = 0;

    erase();
    while (i < MEM_S) {
        if (e->a[i].new_color_count > 0)
            attron(A_BOLD);
        attron(COLOR_PAIR(e->a[i].color));
        printw("%02X", 0xFF & e->a[i].hex);
        attroff(COLOR_PAIR(e->a[i].color));
        if (e->a[i].new_color_count > 0) {
            attroff(A_BOLD);
            e->a[i].new_color_count -= 1;
        }
        printw(" ");
        if ((i + 1) % (128 / 2) == 0)
            printw("\n");
        i++;
    }
    ft_print_game_stats(e);
}

void ft_print_normal(t_env *e)
{
    int hex = 0;

    for (int i = 0; i < MEM_S; i++) {
        if ((i) % (32) == 0)
            ft_printf("%X%c: ", hex, '\t');
        ft_printf("%02X%c", 0xFF & e->a[i].hex, (((i + 1) % 32) == 0)
        ? '\n' : ' ');
        if ((i + 1) % (32) == 0) {
            hex += 32;
        }
    }
    ft_declare_winner(e);
    exit(0);
}

void ft_print_arena(t_env *e)
{
    if (e->bonus_2d) {
        ft_print_bonus(e);
    }
    if (e->dump) {
        if (e->tot_cycle >= e->dump_value)
            ft_print_normal(e);
    }
}

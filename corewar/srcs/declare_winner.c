/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** declare_winner.c
*/

#include "vm.h"

/*
** Have one option with bonus, and one without
*/

void ft_declare_winner(t_env *e)
{
    if (e->bonus_2d) {
        attron(COLOR_PAIR(e->winner + 1 % 6));
        printw("Contestant %d, \"%s\", has won !\n",
        e->player[e->winner].nbr, e->player[e->winner].name);
        attroff(COLOR_PAIR(e->winner + 1 % 6));
        refresh();
        getch();
        endwin();
    } else if (e->winner != -1) {
        ft_printf("Le joueur %d (%s) a gagné.\n",
        e->player[e->winner].nbr, e->player[e->winner].name);
    }
}

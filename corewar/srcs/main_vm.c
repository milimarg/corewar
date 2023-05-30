/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** main_vm.c
*/

#include "vm.h"

int main(int ac, char **av)
{
    t_env e = {0};

    if (ac == 1)
        ft_error_usage();
    init_e(&e, av);
    ft_parse_flags(&e, ac, av);
    ft_files_to_string(&e);
    init_players(&e);
    ft_parsing(&e);
    ft_build_arena(&e);
    ft_init_cursor(&e);
    ft_move_cursors(&e);
    ft_declare_winner(&e);
    ft_exit(&e, 0);
    return (0);
}

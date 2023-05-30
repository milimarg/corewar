/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** error.c
*/

#include "vm.h"

void ft_clean_head(t_cursor *head)
{
    t_cursor *temp = NULL;

    while (head) {
        if (head->next) {
            temp = head;
            head = head->next;
            free(temp);
        }
        if (head->counter) {
            free(head);
            head = NULL;
        }
    }
}

void ft_error_usage(void)
{
    ft_putstr_fd(" Usage:\n \
    Example: ./corewar -visual -n -1 filename.cor\n \
    GUI: ./corewar -visual [Players]\n \
    Default Player Numbers: 1, 2, 3, 4...\n \
    Change Player Number: -n -1 filename.cor\n \
    Dump: ./corewar -dump 300 [Players](prints the memory after 300 cycles)\n \
    Game on! 👾 🤖 🔫 \n", 2);
    exit(1);
}

void ft_error_msg(int i)
{
    static const char *msg[] = {
            "\x1b[31m[Failed to open]\x1b[0m ",
            "\x1b[31m[Failed to read file]\x1b[0m ",
            "\x1b[31m[Failed to close file]\x1b[0m ",
            "\x1b[31m[Wrong Corewar Exec Magic]\x1b[0m ",
            "\x1b[31m[Incorrect Name Chars]\x1b[0m ",
            "\x1b[31m[Player size too big]\x1b[0m ",
            "\x1b[31m[Wrong int value]\x1b[0m ",
            "\x1b[31m[Too many players]\x1b[0m ",
            "\x1b[31m[Duplicate player number]\x1b[0m ",
            "\x1b[31m[Incorrect comment chars]\x1b[0m "
    };
    if (i >= 1 && i <= 10)
        ft_putstr_fd(msg[i - 1], 2);
    else
        ft_putstr_fd("\x1b[31m[ERROR]\x1b[0m ", 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

void ft_error_msg_second(int i)
{
    static const char *msg[] = {
            "\x1b[31m[Too few arguments for -dump]\x1b[0m ",
            "\x1b[31m[-dump value is larger than int max]\x1b[0m ",
            "\x1b[31m[Too few arguments for -n flag]\x1b[0m ",
            "\x1b[31m[Non numerical chars in numb input]\x1b[0m ",
            "\x1b[31m[Wrong int value for -n flag.]\x1b[0m ",
            "\x1b[31m[Wrong file type. Usage: .cor]\x1b[0m ",
            "\x1b[31m[The file size is too large.]\x1b[0m ",
            "\x1b[31m[Too few arguments for -bonus flag]\x1b[0m ",
            "\x1b[31m[Wrong int value for -dump flag]\x1b[0m ",
            "\x1b[31m[Incorrect comment chars]\x1b[0m "
    };
    if (i >= 11 && i <= 20)
        ft_putstr_fd(msg[i - 11], 2);
    else
        ft_putstr_fd("\x1b[31m[ERROR]\x1b[0m ", 2);
    ft_putstr_fd("\n", 2);
    exit(1);
}

void ft_exit(t_env *e, int i)
{
    if (e->head)
        ft_clean_head(e->head);
    if (i > 0 && i < 11)
        ft_error_msg(i);
    else if (i > 10)
        ft_error_msg_second(i);
}

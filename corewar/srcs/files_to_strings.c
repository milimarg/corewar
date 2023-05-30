/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** files_to_strings.c
*/

#include "vm.h"

int ft_string_len(t_env *e, int i)
{
    char buff[BUFF_SIZE + 1] = {0};
    int ret = 1;
    int fd = open(e->files[e->player[i].file_pos], O_RDONLY);

    e->player[i].len = 0;
    if (fd == -1)
        ft_exit(e, 1);
    while (ret > 0) {
        ret = read(fd, buff, BUFF_SIZE);
        if (ret != 0)
            e->player[i].len += ret;
    }
    if (e->player[i].len > TOTAL_SIZE)
        ft_exit(e, 17);
    if (close(fd) == -1)
        ft_exit(e, 3);
    if (ret == -1)
        ft_exit(e, 2);
    return (e->player[i].len);
}

void ft_files_to_string(t_env *e)
{
    int i = 0;
    int fd = 0;
    int len = 0;

    while (i < e->player_amount) {
        if (ft_strlen(e->files[e->player[i].file_pos]) <= 4 ||
        ft_strcmp(e->files[e->player[i].file_pos] +
        ft_strlen(e->files[e->player[i].file_pos]) - 4, ".cor"))
            ft_exit(e, 16);
        len = ft_string_len(e, i);
        if ((fd = open(e->files[e->player[i].file_pos], O_RDONLY)) == -1)
            ft_exit(e, 1);
        if (read(fd, e->player[i].string, e->player[i].len) == -1)
            ft_exit(e, 2);
        e->player[i].string[len] = '\0';
        if (close(fd) == -1)
            ft_exit(e, 3);
        i++;
    }
}

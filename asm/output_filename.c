/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** output_filename.c
*/

#include <stdlib.h>
#include "asm.h"

char *create_output_filename(int len, char *filename, int file_len)
{
    char *new_str = malloc(sizeof(char) * (len + 3 + 1));

    new_str[0] = 0;
    new_str = ft_strncat(new_str, &filename[file_len - len], len - 2);
    new_str = ft_strcat(new_str, ".cor");
    return (new_str);
}

char *get_output_filename(char *filename)
{
    int file_len = ft_strlen(filename);
    int len = file_len;
    int breaked = 0;

    for (; len > 0; len--) {
        if (filename[len] == '/') {
            breaked = 1;
            break;
        }
    }
    len = (breaked) ? len + 1 : len;
    len = file_len - len;
    if (ft_strcmp(&filename[file_len - 2], ".s") != 0) {
        write(2, "asm: wrong extension\n", 21);
        return (NULL);
    }
    return (create_output_filename(len, filename, file_len));
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strsplit.c
*/

#include <stdlib.h>
#include "libft.h"

static int check_str_content(char const *s, char c, int *m_i[2], int w)
{
    int *m = m_i[0];
    int *i = m_i[1];

    for (; s[*i] != c; (*i)++) {
        *m = 1;
        if (s[*i] == '\0')
            return (w + 1);
    }
    return (-1);
}

static int ft_cntwrd(char const *s, char c)
{
    int i = 0;
    int w = 0;
    int m = 0;
    int output = 0;

    for (; s[i] != '\0'; i++) {
        m = 0;
        output = check_str_content(s, c, (int *[2]){&m, &i}, w);
        if (output != -1)
            return (output);
        if (m == 1)
            w++;
    }
    return (w);
}

static int ft_untilc(const char *s, char c)
{
    int len = 0;

    for (; *s != c && *s != '\0'; s++)
        len++;
    return (len);
}

char **ft_strsplit(char const *s, char c)
{
    unsigned int i = 0;
    unsigned int f = 0;
    int w = -1;
    char **list = NULL;

    if (s == NULL)
        return (NULL);
    list = (char **)malloc(sizeof(*list) * ft_cntwrd(s, c) + 1);
    if (!list)
        return (NULL);
    for (; ++w < ft_cntwrd(s, c); f = f + i) {
        for (i = 0; s[i + f] == c; f++);
        i = ft_untilc(&s[f], c);
        list[w] = ft_strnew(i);
        if (!(list[w]))
            return (NULL);
        list[w] = (i > 0) ? ft_strncpy(list[w], &s[f], i) : list[w];
    }
    list[w] = NULL;
    return (list);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strnstr.c
*/

#include <string.h>
#include "libft.h"

static char *find_needle_in_haystack(const char *needle, const char *haystack,
size_t len, size_t *i_j[2])
{
    size_t *i = i_j[0];
    size_t *j = i_j[1];

    *j = 0;
    for (; needle[*j] == haystack[*i + *j] && (*i + *j < len); (*j)++)
        if (needle[*j + 1] == '\0')
            return ((char *)haystack + *i);
    (*i)++;
    return (NULL);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i = 0;
    size_t j = 0;
    char *output = NULL;

    if (*needle == '\0' || needle == NULL)
        return ((char *)haystack);
    while (haystack[i] != '\0' && i < len) {
        output = find_needle_in_haystack(needle, haystack, len,
        (size_t *[2]){&i, &j});
        if (output != NULL)
            return (output);
    }
    return (NULL);
}

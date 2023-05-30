/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_strstr.c
*/

#include <string.h>
#include "libft.h"

static char *compare_needle_in_haystack(const char *haystack,
const char *needle, int i)
{
    for (int j = 0; needle[j] == haystack[i + j]; j++) {
        if (needle[j + 1] == '\0') {
            return ((char *)haystack + i);
        }
    }
    return (NULL);
}

char *ft_strstr(const char *haystack, const char *needle)
{
    int i = 0;
    char *output = NULL;

    if (*needle == '\0')
        return ((char *)haystack);
    for (; haystack[i] != '\0'; i++) {
        output = compare_needle_in_haystack(haystack, needle, i);
        if (output != NULL)
            return (output);
    }
    return (NULL);
}

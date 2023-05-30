/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_wstrings.c
*/

#include "ft_print.h"

void calc_wsize(wchar_t *str, int *len, int *totlen, int *i)
{
    int charlen = 0;
    int end = 0;

    while (str[*len] && *totlen <= *i && end != 1) {
        charlen = wchars_size(str[*len]);
        if ((charlen + *totlen) <= *i) {
            *totlen += charlen;
            charlen = 0;
        }
        if (charlen + *totlen >= *i)
            end = 1;
        *len = *len + 1;
    }
}

int wstrings_size(wchar_t *str, int i)
{
    int len = 0;
    int totlen = 0;

    if (!str)
        return (6);
    if (i == -1)
        for (; str[len]; len++)
            totlen += (wchars_size(str[len]));
    else
        calc_wsize(str, &len, &totlen, &i);
    return (totlen);
}

void ft_putwstr_cut(wchar_t *str, int i)
{
    int len = 0;
    int totlen = 0;
    int charlen = 0;
    int end = 0;

    if (!str)
        str = L"(null)";
    for (; str[len] != '\0' && totlen <= i && end != 1; len++) {
        charlen = (wchars_size(str[len]));
        if (totlen + charlen <= i) {
            ft_printwchar(str[len]);
            totlen += charlen;
            charlen = 0;
        }
        if (charlen + totlen >= i)
            end = 1;
    }
}

void wstrings(wchar_t *str, t_vars *e)
{
    e->printlen = wstrings_size(str, e->pointlen);
    if (e->width < e->printlen)
        ft_putwstr_cut(str, e->printlen);
    if (e->width > e->printlen && e->align == TRUE) {
        ft_putwstr_cut(str, e->printlen);
        printspace(e->width - e->printlen, ' ', e);
    }
    if (e->width > e->printlen && e->align == FALSE) {
        printspace(e->width - e->printlen, ' ', e);
        ft_putwstr_cut(str, e->printlen);
    }
    e->totcount += e->printlen;
}

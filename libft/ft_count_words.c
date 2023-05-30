/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_count_words.c
*/

static int check_content_of_word(char const *s, int *i_m[2], int w, char c)
{
    int *i = i_m[0];
    int *m = i_m[1];

    for (; s[*i] != c; (*i)++) {
        *m = 1;
        if (s[*i] == '\0')
            return (w + 1);
    }
    return (-1);
}

int ft_count_words(char const *s, char c)
{
    int w = 0;
    int m = 0;
    int content_output = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        m = 0;
        content_output = check_content_of_word(s, (int *[2]){&i, &m}, w, c);
        if (content_output != -1)
            return (content_output);
        if (m == 1)
            w++;
    }
    return (w);
}

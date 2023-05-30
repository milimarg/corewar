/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** asm.h
*/

#ifndef ASM_H_
    #define ASM_H_
    #include <stdio.h>
    #include "op.h"
    #include "../libft/libft.h"
    #define char_is_visible(c) (c > 32 && c < 127)
    #define char_is_number(c) (c >= '0' && c <= '9')
    #define char_is_alpha_min(c) (c >= 'a' && c <= 'z')
    #define char_is_alpha_maj(c) (c >= 'A' && c <= 'Z')
    #define char_is_alpha(c) (char_is_alpha_min(c) || char_is_alpha_maj(c))
    #define is_register_valid(reg) (reg >= 1 && reg <= REG_NUMBER)
    #define get_cmd(copy) op_tab[copy->op_tab_index].mnemonique

typedef enum param_type_s {
    REGISTER = 0b01,
    DIRECT = 0b10,
    INDIRECT = 0b11,
    OTHERWISE = 0b00
} param_type_t;

typedef struct infos_s {
    char **array;
    int op_tab_index;
    param_type_t *types;
    struct infos_s *next;
} infos_t;

typedef struct label_s {
    char *name;
    int line_pos;
    short *distances;
    int distances_nb;
    int index;
    struct label_s *next;
} label_t;

typedef struct asm_s {
    int name_cmd_len;
    int comment_cmd_len;
    int prog_name_len;
    int prog_comment_len;
    int found_name;
    int found_comment;
    char **cmd_value;
    int index_value;
    header_t header;
    infos_t *infos;
    int labels_nb;
    label_t *label_list;
    int output_fd;
} asm_t;

int get_champion_name(char *buffer, asm_t *env);
int get_champion_comment(char *buffer, asm_t *env);
char *clean_str_start(char *str);
void get_live(char *buffer, asm_t *env);
char *clean_str_end(char *str);
int write_data_in_file(asm_t *env, int get_prog_size_or_write);
void add_to_list(infos_t **head, int indx, char **values, param_type_t *types);
int error_handling(asm_t *env);

int reverse_int(int n);
short reverse_short(short n);

char *clean_str_end(char *str);
char *clean_str_start(char *str);
int is_str_alpha(const char *s);

int write_register(int get_prog_size_or_write, asm_t *env, infos_t *copy,
int i);
int write_direct(int get_prog_size_or_write, asm_t *env, infos_t *copy, int i);
int write_indirect(int get_prog_size_or_write, asm_t *env, infos_t *copy,
int i);

void save_register(param_type_t *tab, int i, asm_t *env);
void save_direct(param_type_t *tab, int i, asm_t *env);
void save_indirect(param_type_t *tab, int i, asm_t *env);

char *create_output_filename(int len, char *filename, int file_len);
char *get_output_filename(char *filename);

void get_labels_nb(asm_t *env, char *buffer, int line_pos);
void detect_label_in_buffer(asm_t *env);

int init_env(asm_t *env, FILE **fd, char *filename);

short get_size_of_parameter(infos_t *node, int index);
short get_instruction_weight(infos_t *copy);

void write_data_exceptions(infos_t *copy, int i, int get_prog_size_or_write,
asm_t *env);

#endif /*ASM_H_*/

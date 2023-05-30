/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** op.h
*/

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/
#ifndef OP_H
    #define OP_H

    #define IND_SIZE 2
    #define REG_SIZE 4
    #define DIR_SIZE REG_SIZE

    #define REG_CODE 1
    #define DIR_CODE 2
    #define IND_CODE 3

    #define MAX_ARGS_NUMBER 4
    #define MAX_PLAYERS 4
    #define MEM_S (4 * 1024)
    #define IDX_MOD (MEM_S / 8)
    #define CHAMP_MAX_SIZE (MEM_S / 6)

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','

    #define alpha_min "abcdefghijklmnopqrstuvwxyz"
    #define alpha_maj "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #define numeric "0123456789"

    #define LABEL_CHARS alpha_min "_" numeric "'+-*/=.," alpha_maj
    #define CMD_CHARS " " alpha_min "_" numeric "'+-*/=.," alpha_maj "!"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define REG_NUMBER 16

    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 50
    #define NBR_LIVE 21
    #define MAX_CHECKS 9

typedef char t_arg_type;

    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8

    #define PROG_NAME_LENGTH (128)
    #define COMMENT_LENGTH (2048)
    #define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct s_header {
    unsigned int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    unsigned int prog_size;
    char comment[COMMENT_LENGTH + 1];
} t_header;

typedef struct s_op {
    char    name[PROG_NAME_LENGTH];
    int        nb_params;
    char    params_type[3];
    int        id;
    int        cycles;
    char    description[50];
    int        acb;
    int        label_size;
} t_op;

#endif

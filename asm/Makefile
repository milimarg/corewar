##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-corewar-florent.guittre
## File description:
## Makefile
##

SRC	=	asm.c \
		op.c \
		get_file_infos.c \
		parser_part0.c \
		write_data_in_file.c \
		add_to_list.c \
		utils.c \
		clean_str.c \
		write_data_per_types.c \
		save_string_per_types.c \
		output_filename.c \
		get_labels.c \
		search_labels.c \
		check_errors.c \
		init_env.c \
		get_infos_for_labels.c \
		write_data_exceptions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) -L../libft/ -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

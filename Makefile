##
## EPITECH PROJECT, 2023
## B-CPE-200-STG-2-1-corewar-florent.guittre
## File description:
## Makefile
##

NAME	=	compile
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I.
RM		=   rm -f
LIBFT	=	 -L./libft -lft

LIBFT_PATH	= ./libft
VM_PATH	= ./corewar
ASM_PATH	= ./asm

all:	$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@make -C $(VM_PATH)
	@make -C $(ASM_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(VM_PATH) clean
	@make -C $(ASM_PATH) clean

fclean:	clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(VM_PATH) fclean
	@make -C $(ASM_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re

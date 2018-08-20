NAME = asm

FILE_C =  main.c libft_d.c name.c comment.c g_operations.c cmd.c args.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc

FLAG = -Wall -Wextra -Werror -g

LIB_INC = -I libft/

LIBNAME = ./libft/libft.a

all: $(NAME)

$(LIBNAME): ./libft/libft.h
	@make -C ./libft

$(NAME): $(LIBNAME) $(FILE_O)
	@$(GCC) $(FILE_O) ./libft/libft.a -o $(NAME)
	@echo "-----====== COMPLETE ======-----"

%.o: %.c
	@$(GCC) $(FLAG) -c $< $(LIB_INC)

clean:
	@make -C ./libft clean
	@rm -f $(FILE_O)
	@echo "---=== CLEANING DONE RIGHT ===---"

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all
	@make -C ./libft fclean
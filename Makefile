COMPILER = cc
FLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -fsanitize=address,undefined -Werror=address -Wnull-dereference -g
PROGRAM_NAME = push_swap

MANDATORY = main.c utils.c utils2.c stack_op1.c stack_op2.c stack_op3.c stack_op4.c sorting.c one_arg_utils.c sorting_utils.c
MANDATORY_OBJECTS = $(MANDATORY:.c=.o)
LIBFT_A = libft/libft.a

all: libft mandatory

mandatory: $(MANDATORY_OBJECTS)
	$(COMPILER) $(FLAGS) $(MANDATORY_OBJECTS) $(LIBFT_A) -o $(PROGRAM_NAME)

debug: fclean libft $(MANDATORY_OBJECTS)
		$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(MANDATORY_OBJECTS) $(LIBFT_A) -o $(PROGRAM_NAME)

libft:
	cd libft ; make

libft_clean:
	cd libft ; make clean

libft_fclean:
	cd libft ; make fclean

libft_re:
	cd libft ; make re

clean: libft_clean
	rm -rf *.o *.out *.gch .vscode

fclean: clean libft_fclean
	rm -rf $(PROGRAM_NAME)

re: fclean all

.PHONY: all clean fclean re libft libft_clean libft_fclean libft_re debug

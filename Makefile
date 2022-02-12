NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror -O2
INC = -I ./headers -I libft/
LBLNK = -l readline

SRC_F = main.c \
		prompt.c \
		env.c \
		lexer.c \
		quote_checker.c \
		quote_remover.c \
		expand_env.c \
		signals.c \
		get_path.c \
		builtins.c

AUX_F = strings.c
EXEC_F = executor.c

SRC = $(addprefix src/, $(SRC_F))
SRC += $(addprefix src/aux/, $(AUX_F))
SRC += $(addprefix src/executor/, $(EXEC_F))

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $@ $(LBLNK)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CFLAGS = -Wall -Wextra -Werror -g
debug: $(OBJ)
	$(MAKE) -C ./libft debug
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) $(LBLNK)

.PHONY: all clean fclean re debug

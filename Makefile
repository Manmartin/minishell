NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror -O2
INC = -I ./headers -I libft/
LBLNK = -lreadline -L /Users/acrucesp/.brew/Cellar/readline/8.1.2/lib 

SRC_F = main.c \
		prompt.c \
		env.c \
		lexer.c \
		quote_checker.c \
		quote_remover.c \
		expand_env.c \
		signals.c \
		parser.c \
		syntax_errors.c

SRC = $(addprefix src/, $(SRC_F))

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -I  /Users/acrucesp/.brew/Cellar/readline/8.1.2/include -c $^ -o $@

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

debug: CFLAGS = -Wall -Wextra -Werror -g3 
debug: $(OBJ)
	$(MAKE) -C ./libft debug
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) $(LBLNK)

.PHONY: all clean fclean re debug

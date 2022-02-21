NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror -O2
INC = -I ./headers -I libft/
LBLNK = -l readline

SRC_F = main.c \
		env.c \
		expand_env.c \
		signals.c \
		get_path.c

AUX_F = strings.c
PARSER_F =  parse_string.c parser.c free_cmds.c syntax_errors.c quote_checker.c	quote_remover.c lexer.c
EXEC_F = executor.c redirects.c
BUILTINS_F = builtins.c

SRC = $(addprefix src/, $(SRC_F))
SRC += $(addprefix src/aux/, $(AUX_F))
SRC += $(addprefix src/parser/, $(PARSER_F))
SRC += $(addprefix src/executor/, $(EXEC_F))
SRC += $(addprefix src/builtins/, $(BUILTINS_F))

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

#debug: CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
debug: CFLAGS = -Wall -Wextra -Werror -g3 
debug: $(OBJ)
	$(MAKE) -C ./libft debug
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) $(LBLNK)


.PHONY: all clean fclean re debug

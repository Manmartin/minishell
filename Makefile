NAME = minishell

CC = clang
CFLAGS = -Wall -Wextra -Werror -O2
INC = -I ./headers -I libft/ -I /Users/acrucesp/.brew/Cellar/readline/8.1.2/include 
LBLNK = -L /Users/acrucesp/.brew/Cellar/readline/8.1.2/lib -lreadline

SRC_F = main.c \
		signals.c \
		get_path.c 

AUX_F = strings.c shell_exit.c
PARSER_F =  parse_string.c parser.c free_cmds.c syntax_errors.c quote_checker.c	lexer.c aux_parser.c
EXEC_F = executor.c redirects.c aux_exec.c aux_rdrc.c heredocs.c
BUILTINS_F = builtins.c export.c env.c echo.c cd.c pwd.c env_builtins.c unset.c exit.c show_export.c aux_export.c
ENV_F = env.c expand_env.c aux_expand.c quote_remover.c relexer.c

SRC = $(addprefix src/, $(SRC_F))
SRC += $(addprefix src/utils/, $(AUX_F))
SRC += $(addprefix src/parser/, $(PARSER_F))
SRC += $(addprefix src/executor/, $(EXEC_F))
SRC += $(addprefix src/builtins/, $(BUILTINS_F))
SRC += $(addprefix src/env/, $(ENV_F))

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

debug: CFLAGS = -Wall -Wextra -Werror -g3 
debug: $(OBJ)
	$(MAKE) -C ./libft debug
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME) $(LBLNK)


.PHONY: all clean fclean re debug

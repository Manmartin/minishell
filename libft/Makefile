NAME = libft.a

CC = clang 
CFLAGS = -Wall -Wextra -Werror -O2
INC = -I ./

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	  ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strnstr.c\
	  ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c\
	  ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
	  ft_strtrim.c ft_split.c ft_trimf.c ft_nsep.c ft_itoa.c ft_ndigit.c ft_power.c\
	  ft_strmapi.c ft_strrchr.c ft_isalnum.c ft_lstnew.c ft_lstsize.c ft_lstlast.c\
	  ft_lstiter.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
	  ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstlast.c\
	  ft_lstmap.c ft_strchrs.c ft_itoa_base.c ft_isforshell.c ft_isenv.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CFLAGS = -Wall -Wextra -Werror -g3
debug: all

.PHONY: all clean fclean re debug

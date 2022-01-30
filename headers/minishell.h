/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/30 20:41:20 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Functions per library:
 *		unistd.h:	write
 *		stdio.h:	printf
 *		stdlib.h:	malloc, free, getenv
 *		fcntl.h:	open
 *		stdbool:	bool type
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>
# include <resources.h>

#define TYPES ">,>>,<,<<"

typedef struct	s_cmd {
	t_list	*rdctns;
	char	**argv;
	int		argc;
}				t_cmd;

typedef struct	s_rdctns {
	char 	*type;
	char	*file;
}				t_rdnctns;

typedef struct s_data {
	char	*pwd;
	char	*prompt;
	char	**env;
	int		sz_env;
	char	*user;
	char	*line;
}				t_data;

extern t_data	g_data;

/* main.c*/

void	init_data(void);

/* env.c */

void	init_env(char **env);
char	*get_env(const char *const str);

/* prompt.c*/

char	*get_prompt(void);

/* lexer.c */

t_list	*lexer(const char *line);

/* parser.c */
int		parser(t_list *tokens);
#endif

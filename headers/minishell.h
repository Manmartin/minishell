/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/26 14:59:15 by manmarti         ###   ########.fr       */
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
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>
# include <resources.h>

enum	types {input, output, append, here_dcmnt };

typedef struct	s_cmd {
	t_list	*rdrcs;
	char	**argv;
	int		argc;
}				t_cmd;

typedef struct	s_rdrc {
	enum	types type;
	char	*file;
}				t_rdrc;



typedef struct s_data {
	char	*pwd;
	char	*prompt;
	char	**env;
	int		sz_env;
	char	*user;
	char	*line;
}				t_data;

/*
 *	t_flags disable line split while any quotes are open
 *		-d_qts: True if double quotes are open
 *		-s_qts: True if sigle quotes are open
*/

typedef struct s_flags {
	bool	d_qts;
	bool	s_qts;
}	t_flags;

extern t_data	g_data;

/* main.c*/

void	init_data(void);
void	free_data(void);

/* env.c */

void	init_env(char **env);
char	*get_env(const char *const str);
void	free_env(void);

/* prompt.c*/

char	*get_prompt(void);

/* lexer.c */

t_list	*lexer(const char *line);

/* quote_checker.c */

bool	quote_checker(t_list *tokens);

/* expand_env.c */

void	expand_env(t_list *tokens);
void	exit_error(char *msg);

/* quote_remover.c */

void	quote_remover(char **str);

/* signals.c */

void	signals(void);

/* executor.c */

//void	executor(s_cmd *cmd);

char	*get_path(const char *const cmd);

/* strings.c */

char	*append_string(char *s1, char *s2);
char	*char_append(char *str1, const char c);

/* executor.c */
	
bool	is_builtin(const char *const cmd);

/* get_path.c */

char	*get_path(const char *const cmd);

#endif

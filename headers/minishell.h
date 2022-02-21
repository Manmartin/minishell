/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/21 22:22:42 by manuel           ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <libft.h>
# include <resources.h>

typedef struct s_cmd {
	t_list	*rdtns;
	char	**argv;
	char	*pathname;
	int		argc;
}				t_cmd;

typedef struct s_rdtns {
	char	*type;
	char	*file;
}				t_rdtns;

typedef struct s_data {
	char	**env;
	int		sz_env;
	int		n_cmd;
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

/* lexer.c */

t_list	*lexer(const char *line);

/* quote_checker.c */

bool	quote_checker(t_list *tokens);

/* expand_env.c */

void	expand_env(t_cmd **cmds);
void	exit_error(char *msg);

/* quote_remover.c */

void	quote_remover(char **str);

/* signals.c */

void	signals(void);

/* parser.c */

t_cmd	**parser(t_list *tokens);

/* free_cmds.c */

t_cmd	**free_cmds(t_cmd **cmds, int j, int n);
void	free_redirections(void *redirections);
int		free_types(char **types);

/* systax_error.c */

int		r_syntax_errors(t_list **tokens);
int		p_syntax_errors(t_list *tokens, int from);

/* strings.c */

char	*append_string(char *s1, char *s2);
char	*char_append(char *str1, const char c);

/* executor.c */

void	executor(t_cmd	**cmd);
void	make_dup(int fd[2], int used, int dupped);

/* redirects.c*/

void	redirects(t_list *rdrc);

/* builtins.c */

bool	is_builtin(const char *const cmd);
void	exec_builtin(t_cmd *cmd);

/* get_path.c */

void	put_paths(t_cmd **cmds);

/* parse_string.c */

t_cmd	**parse_string(char *input);

#endif

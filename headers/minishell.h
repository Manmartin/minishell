/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2022/03/01 10:48:47 by manmarti         ###   ########.fr       */
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
	int		fd;
	int		fd_closed;
	char	**env;
	int		sz_env;
	int		n_cmd;
	int		*pids;
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
int		select_env(char **s, int i);

/* quote_remover.c */

void	quote_remover(char **str);

/* signals.c */

void	signals(void);
void	builtin_signals(int sig);
void	manage_signals(int sig);
void	heredocs_signals(int sig);

/* parser.c */

t_cmd	**parser(t_list *tokens);
t_cmd	**alloc_cmds(int n_pipes);
void	alloc_cmd(t_cmd ***cmds, int i, int j, t_list *tokens);
void	load_cmds(t_list **tokens, t_cmd ***cmds, int (*i)[2], int n_pipes);
int		count_nodes(t_list *tokens, int positions);
int		load_cmd(t_list **tokens, t_cmd *cmds, int *i);

/* free_cmds.c */

t_cmd	**free_cmds(t_cmd **cmds, int j, int n);
void	free_all_cmds(t_cmd **cmds);
void	free_redirections(void *redirections);
int		free_types(char **types);
t_list	*clean_args(t_list **args);

/* systax_error.c */

int		r_syntax_errors(t_list **tokens);
int		p_syntax_errors(t_list *tokens, int from);

/* strings.c */

char	*append_string(char *s1, char *s2);
char	*char_append(char *str1, const char c);

/* executor.c */

void	executor(t_cmd	**cmd);
void	make_dup(int fd[2], int used, int dupped);

/* aux_exec.c */

void	make_dup(int fd[2], int used, int dupped);
void	add_pid(int pid);
void	free_exec(void);

/* redirects.c*/

void	redirects(t_list *rdrc);

/* heredocs.c */

int		make_heredocs(t_cmd **cmds);

/* aux_rdrc.c */

void	expand_heredocs(char **str);
char	*create_tmpfile(size_t len);

/* builtinsc */

bool	is_builtin(const char *const cmd);
void	exec_builtin(t_cmd *cmd);
int		export(t_cmd *cmd);
void	set_env(char *name, char *value);
int		env(void);
int		echo(t_cmd *cmd);
int		pwd(void);
int		should_move(t_cmd **cmd);
int		cd_exec(t_cmd *cmd);
int		env_builtins(t_cmd **cmds);
int		cd(t_cmd *cmd);
void	unset(t_cmd *cmd);
void	exitchan(t_cmd **cmd);

/* get_path.c */

void	put_paths(t_cmd **cmds);

/* parse_string.c */

t_cmd	**parse_string(char *input);

/* shell_exit.c */

void	exit_error(char *msg);
void	exit_shell_error(char *msg, int code);

#endif

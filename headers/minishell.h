/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/10 16:44:11 by manmarti         ###   ########.fr       */
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

#endif

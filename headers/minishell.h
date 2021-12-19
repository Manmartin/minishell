/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2021/12/19 19:26:39 by acrucesp         ###   ########.fr       */
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
char	**parser(t_list *tokens);
#endif

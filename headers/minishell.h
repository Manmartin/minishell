/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:49:29 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/22 23:42:32 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Functions per library:
 *		unistd.h:	write
 *		stdio.h:	printf
 *		stdlib.h:	malloc, free
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

typedef struct s_data {
	char	*pwd;
	char	*prompt;
	char	*user;
	char	*line;
}				t_data;

extern t_data	g_data;

#endif

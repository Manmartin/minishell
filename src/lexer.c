/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:38:25 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:24:19 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

typedef struct s_flags {
	bool	d_quotes;
	bool	s_quotes;
}	t_flags;

t_list	*lexer(const char *const line)
{
	t_list	*args;
	t_flags	flags;
	int		i;
	int		origin;

	i = 0;
	args = 0;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (line[i])
	{
		origin = i;
		while ((!ft_isforshell(line[i]) || flags.d_quotes || flags.s_quotes)
			&& line[i])
		{
			if (line[i] == '\'')
				flags.s_quotes = !flags.s_quotes;
			else if (line[i] == '"')
				flags.d_quotes = !flags.d_quotes;
			i++;
		}
		ft_lstadd_back(&args, ft_lstnew(ft_substr(&line[origin], 0,
					i - origin)));
		while (ft_isforshell(line[i]))
		{
			if (line[i] != ' ')
				ft_lstadd_back(&args, ft_lstnew(ft_strdup("|")));
			i++;
		}
	}
	return (args);
}

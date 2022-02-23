/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:38:51 by manuel            #+#    #+#             */
/*   Updated: 2022/02/23 20:00:05 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	**parse_string(char *input)
{
	t_list	*tokens;
	t_cmd	**cmds;

	tokens = lexer(input);
	free(input);
	if (tokens && quote_checker(tokens))
	{
		cmds = parser(tokens);
		if (cmds)
		{
			expand_env(cmds);
			put_paths(cmds);
			g_data.pids = ft_calloc(g_data.n_cmd, sizeof(int));
		}
		return (cmds);
	}
	return (NULL);
}

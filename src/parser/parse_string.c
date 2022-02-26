/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:38:51 by manuel            #+#    #+#             */
/*   Updated: 2022/02/26 20:28:53 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	**parse_string(char *input)
{
	t_list	*tokens;
	t_cmd	**cmds;

	tokens = lexer(input);
	free(input);
	if (!tokens)
		return (NULL);
	if (quote_checker(tokens))
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
	else
		ft_putendl_fd("Error: bad quotes", STDERR_FILENO);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:38:51 by manuel            #+#    #+#             */
/*   Updated: 2022/02/22 16:43:41 by manuel           ###   ########.fr       */
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
		}
		return (cmds);
	}
	return (NULL);
}

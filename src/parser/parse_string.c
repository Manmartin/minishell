/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:38:51 by manuel            #+#    #+#             */
/*   Updated: 2022/02/21 11:04:07 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	**parse_string(char *input)
{
	t_list	*tokens;
	t_cmd	**cmds;

	tokens = lexer(input);
	free(input);
	if (quote_checker(tokens))
	{
		cmds = parser(tokens);
		if (cmds)
			expand_env(cmds);
		return (cmds);
	}
	return (NULL);
}
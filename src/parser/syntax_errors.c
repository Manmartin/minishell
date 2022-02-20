/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:34:35 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/15 23:57:24 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	int	msg_newline(char **types)
{
	write(STDERR_FILENO, "syntax error near unexpected token", 34);
	write(STDERR_FILENO, "`newline'\n", 10);
	return (!free_types(types));
}

int	r_syntax_errors(t_list **tokens)
{	
	int		y;
	char	**types;

	types = ft_split(TYPES, ',');
	y = -1;
	if (!*tokens)
		return (msg_newline(types));
	while (types[++y])
	{
		if (ft_strnstr(types[y], (char *)(*tokens)->content,
			ft_strlen((char *)(*tokens)->content)))
		{
			write(STDERR_FILENO, "syntax error near unexpected token `", 36);
			write(STDERR_FILENO, types[y], ft_strlen(types[y]));
			write(STDERR_FILENO, "'\n", 2);
			return (!free_types(types));
		}
	}
	free_types(types);
	if (!p_syntax_errors(*tokens, 1))
		return (0);
	return (1);
}

int	p_syntax_errors(t_list *tokens, int from)
{
	t_list	*tmp;

	if (!from)
	{
		if (!tokens->next)
			return (0);
		tmp = tokens->next;
	}
	else
		tmp = tokens;
	if (ft_strnstr((char *)tmp->content, "|",
			ft_strlen((char *)tmp->content)))
	{
		write(STDERR_FILENO, "syntax error near unexpected token `", 36);
		write(STDERR_FILENO, "|\'\n", 2);
		return (0);
	}
	return (1);
}

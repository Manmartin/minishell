/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:34:35 by acrucesp          #+#    #+#             */
/*   Updated: 2022/02/12 21:38:31 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	r_syntax_errors(t_list **tokens)
{
	// siempre tiene que existir un fichero a la derecha	
	// bash: syntax error near unexpected token `newline'
	//bash-3.2$ >
	//bash: syntax error near unexpected token `newline'
	//if token->next == null
	//bash-3.2$ a > |
	//bash: syntax error near unexpected token `|'
	//if token->next == |
	//bash-3.2$ a > > x
	//bash: syntax error near unexpected token `>'
	//if token->next is redirection
	
	char 	**types;
	int		y;

	types = ft_split(TYPES, ',');
	y = 0;
	if (!*tokens)
	{
		write(1, "syntax error near unexpected token", 34);
		write(1, "`newline'\n", 10);
		return (0);
	}
	while (types[y])
	{
		if (ft_strnstr(types[y], (char *)(*tokens)->content,
			ft_strlen((char *)(*tokens)->content)))
		{
			write(1, "syntax error near unexpected token `", 36);
			write(1, types[y], ft_strlen(types[y]));
			write(1, "'\n", 2);
			return (0);
		}
		y++;
	}
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
		write(1, "syntax error near unexpected token `", 36);
		write(1, "|\n\'", 2);	
		return (0);
	}
	return (1);
}

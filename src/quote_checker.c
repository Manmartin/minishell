/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:37:48 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/10 17:43:13 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	quote_checker(t_list *tokens)
{
	t_flags	flags;
	t_list	*first;
	int		i;
	char	*aux;

	i = 0;
	first = tokens;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (tokens)
	{
		aux = tokens->content;
		while (aux[i])
		{
			if (aux[i] == '\'' && !flags.d_qts)
				flags.s_qts = !flags.s_qts;
			else if (aux[i] == '"' && !flags.s_qts)
				flags.d_qts = !flags.d_qts;
			i++;
		}
		if (flags.d_qts || flags.s_qts)
		{
			ft_lstclear(&first, free);
			return (false);
		}
		i = 0;
		ft_memset(&flags, 0, sizeof(t_flags));
		tokens = tokens->next;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:37:48 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/10 17:57:19 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	check_flags(t_flags *flags, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !flags->d_qts)
			flags->s_qts = !flags->s_qts;
		else if (str[i] == '"' && !flags->s_qts)
			flags->d_qts = !flags->d_qts;
		i++;
	}
}

bool	quote_checker(t_list *tokens)
{
	t_flags	flags;
	t_list	*first;

	first = tokens;
	ft_memset(&flags, 0, sizeof(t_flags));
	while (tokens)
	{
		check_flags(&flags, tokens->content);
		if (flags.d_qts || flags.s_qts)
		{
			ft_lstclear(&first, free);
			return (false);
		}
		ft_memset(&flags, 0, sizeof(t_flags));
		tokens = tokens->next;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:21:44 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/17 13:58:24 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	remove_quotes(char **s, int init, int end)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_calloc(sizeof(char), ft_strlen(*s) - 1);
	i = 0;
	j = 0;
	while ((*s)[i])
	{
		if (i != init && i != end)
		{
			new_str[j] = (*s)[i];
			j++;
		}
		i++;
	}
	free(*s);
	*s = new_str;
	return (end - 2);
}

void	quote_remover(char **str)
{
	char	*aux;
	t_flags	flags;
	int		i;
	int		init;
	int		end;

	aux = *str;
	ft_memset(&flags, 0, sizeof(t_flags));
	i = 0;
	init = -1;
	end = -1;
	while (aux[i])
	{
		if (aux[i] == '\'' && !flags.d_qts)
		{
			flags.s_qts = !flags.s_qts;
			if (init == -1)
				init = i;
			else
				end = i;
		}
		else if (aux[i] == '"' && !flags.s_qts)
		{
			flags.d_qts = !flags.d_qts;
			if (init == -1)
				init = i;
			else
				end = i;
		}
		if (end != -1)
		{
			i = remove_quotes(&aux, init, end);
			init = -1;
			end = -1;
			*str = aux;
		}
		i++;
	}
}

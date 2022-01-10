
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:37:48 by manmarti          #+#    #+#             */
/*   Updated: 2022/01/10 14:37:48 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	quote_checker(t_list *tokens)
{
	while (tokens)
	{
		
		tokens = tokens->next;
	}	
	return (true);
}

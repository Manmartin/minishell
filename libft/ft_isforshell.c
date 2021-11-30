/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isforshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:53:38 by manmarti          #+#    #+#             */
/*   Updated: 2021/11/30 23:34:43 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
 * Check if a character is a shell action or an arg separator
 */

int	ft_isforshell(char c)
{
	if (c == '|' || c == ' ' || c == '>' || c == '<')
		return (1);
	return (0);
}

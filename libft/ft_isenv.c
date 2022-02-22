/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:02:44 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/22 11:46:30 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	ft_isenv(const char c)
{
	if (ft_isalnum(c) || c == '?' || c == '_')
		return (true);
	return (false);
}

bool	ft_isexp(const char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

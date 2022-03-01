/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:02:44 by manmarti          #+#    #+#             */
/*   Updated: 2022/02/28 20:21:28 by acrucesp         ###   ########.fr       */
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

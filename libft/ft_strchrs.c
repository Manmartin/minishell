/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:29:00 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/13 19:29:28 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchrs(const char *str, char *set)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (set[i])
		{
			if (*str == set[i])
				return ((char *)str);
			i++;
		}
		str++;
	}
	return (0);
}

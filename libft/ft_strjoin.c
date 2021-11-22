/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:35:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/02 18:06:23 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	int		len;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	joinstr = ft_calloc(sizeof(char), len + 1);
	if (!joinstr)
		return (0);
	ft_strlcpy(joinstr, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(joinstr, s2, len + 1);
	return (joinstr);
}

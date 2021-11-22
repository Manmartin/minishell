/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:02:29 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/03 20:49:52 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*cpstr;

	if (!s)
		return (0);
	if (!len || start > ft_strlen(s))
		return (ft_calloc(sizeof(char), 1));
	cpstr = ft_calloc(sizeof(char), len + 1);
	if (!cpstr)
		return (0);
	i = 0;
	while ((char)s[start] && len--)
		cpstr[i++] = (char)s[start++];
	return (cpstr);
}

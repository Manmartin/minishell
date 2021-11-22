/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:26:03 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/04 20:30:41 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	sz;
	char			*ret;

	i = 0;
	if (!s || !f)
		return (0);
	sz = ft_strlen(s) + 1;
	ret = ft_calloc(sizeof(char), sz);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, sz);
	while (ret[i])
	{
		ret[i] = (*f)(i, ret[i]);
		i++;
	}
	return (ret);
}

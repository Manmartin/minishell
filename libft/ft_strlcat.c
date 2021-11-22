/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:05:42 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/30 19:06:29 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	leni;
	size_t	i;

	i = 0;
	lens = ft_strlen(src);
	leni = ft_strlen(dst);
	if (dstsize == 0)
		return (lens);
	else if (dstsize < leni)
		return (lens + dstsize);
	else
		lens = lens + leni;
	while (src[i] && leni + 1 < dstsize)
		dst[leni++] = src[i++];
	dst[leni] = 0;
	return (lens);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:10:02 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/03 15:15:50 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sz;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	sz = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[sz]) && sz)
		sz--;
	return (ft_substr((char *)s1, 0, sz + 1));
}

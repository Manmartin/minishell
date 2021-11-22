/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:19:54 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/02 17:40:10 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*aux;
	int		i;

	i = -1;
	aux = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!aux)
		return (0);
	while (s[++i])
		aux[i] = s[i];
	return (aux);
}

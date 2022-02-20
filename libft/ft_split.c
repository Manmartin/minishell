/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:09:04 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/03 21:21:05 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*aux;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	aux = ft_trimf(s, (char []){c, '\0'});
	ret = ft_calloc(sizeof(char *), ft_nsep(aux, c) + 2);
	if (!ret)
		return (0);
	while (aux[j])
	{
		start = j;
		while (aux[j] != c && aux[j])
			j++;
		ret[i++] = ft_substr(aux, start, j - start);
		if (aux[j])
			j++;
	}
	free(aux);
	return (ret);
}

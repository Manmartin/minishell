/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:17:14 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/01 19:37:59 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;

	if (size > INT_MAX / count || !count || !size)
		return (0);
	aux = malloc(count * size);
	if (!aux)
		return (0);
	ft_bzero(aux, count * size);
	return (aux);
}

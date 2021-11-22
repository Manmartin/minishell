/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:49:35 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/02 19:04:25 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_power(long long int base, long long int power)
{
	long long int	n_aux;

	if (!base)
		return (1);
	if (power < 0)
		return (0);
	n_aux = base;
	while (power-- > 1)
		base *= n_aux;
	return (base);
}

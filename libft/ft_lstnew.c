/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:17:30 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/05 18:58:27 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elmt;

	elmt = (t_list *)ft_calloc(sizeof(*elmt), 1);
	if (!elmt)
		return (0);
	elmt->content = content;
	return (elmt);
}

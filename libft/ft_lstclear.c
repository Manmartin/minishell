/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:26:36 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/07 16:37:05 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*last;

	if (!lst)
		return ;
	while (*lst)
	{
		last = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = last;
	}
}

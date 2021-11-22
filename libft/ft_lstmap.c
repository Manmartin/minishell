/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:46:16 by acrucesp          #+#    #+#             */
/*   Updated: 2021/04/07 18:04:55 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*pstn_new;
	t_list	*pstn_old;

	new_lst = ft_lstnew((*f)(lst->content));
	if (!lst || !new_lst)
		return (0);
	pstn_new = new_lst;
	pstn_old = lst->next;
	while (pstn_old)
	{
		pstn_new->next = ft_lstnew((*f)(pstn_old->content));
		if (!pstn_new->next)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		pstn_new = pstn_new->next;
		pstn_old = pstn_old->next;
	}
	return (new_lst);
}

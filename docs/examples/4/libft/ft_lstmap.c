/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:23:41 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/08 18:23:43 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;
	t_list	*foo;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	foo = ft_lstnew(tmp->content, tmp->content_size);
	if (!foo)
		return (NULL);
	begin = foo;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		foo->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!foo)
			return (NULL);
		lst = lst->next;
		foo = foo->next;
	}
	return (begin);
}

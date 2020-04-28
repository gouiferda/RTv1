/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:24:14 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/06 10:24:15 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (del && alst)
	{
		while (*alst)
		{
			tmp = *alst;
			(*del)((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(tmp);
		}
		*alst = NULL;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:07:16 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/06 10:07:33 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*foo;

	if (!(foo = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		foo->content = NULL;
		foo->content_size = 0;
	}
	else
	{
		foo->content_size = content_size;
		foo->content = malloc(content_size);
		if (!foo->content)
			return (NULL);
		ft_memcpy(foo->content, content, content_size);
		foo->next = NULL;
	}
	return (foo);
}

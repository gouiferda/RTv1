/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:38:26 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/09 18:38:30 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	if (begin_list)
	{
		tmp = begin_list;
		i = 0;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}

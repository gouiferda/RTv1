/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:56:17 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/31 15:56:21 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

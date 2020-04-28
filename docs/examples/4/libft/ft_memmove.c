/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:45:58 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 17:46:06 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t		i;

	i = 0;
	if (dest < src)
	{
		while (i < num)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (num)
		{
			((unsigned char*)dest)[num - 1] = ((unsigned char*)src)[num - 1];
			num--;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:08:57 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/27 17:10:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int value, size_t num)
{
	size_t		i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char*)source)[i] == (unsigned char)value)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)source)[i];
			i++;
			return (dest + i);
		}
		((unsigned char*)dest)[i] = ((unsigned char*)source)[i];
		i++;
	}
	return (NULL);
}

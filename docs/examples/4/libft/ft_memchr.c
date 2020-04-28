/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:47:13 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 17:47:15 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t num)
{
	size_t		i;
	void		*arr;

	i = 0;
	arr = (unsigned char *)str;
	while (i < num)
	{
		if (*(unsigned char *)arr == (unsigned char)value)
			return (arr);
		i++;
		arr++;
	}
	return (NULL);
}

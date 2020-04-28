/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:48:13 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 17:48:16 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (arr1[i] > arr2[i])
			return (arr1[i] - arr2[i]);
		else if (arr1[i] < arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:28:47 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/31 16:28:49 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(size + 1);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = '\0';
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

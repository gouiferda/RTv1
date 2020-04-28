/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:31:51 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/01 17:31:52 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (s)
	{
		i = 0;
		j = len + start;
		arr = (char*)malloc(sizeof(char) * (len + 1));
		if (!arr)
			return (NULL);
		while (start < j)
		{
			arr[i] = s[start];
			start++;
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}

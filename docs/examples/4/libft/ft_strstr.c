/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:06:52 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 19:06:55 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	p;
	char	*arr;

	arr = (char*)str;
	if (!*to_find)
		return (arr);
	i = 0;
	p = 0;
	while (str[i])
	{
		p = 0;
		while (to_find[p] == arr[i + p])
		{
			p++;
			if (to_find[p] == '\0')
				return (arr + i);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:14:38 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 19:14:40 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	p;
	char	*arr;

	arr = (char*)str;
	if (!*to_find)
		return (arr);
	i = 0;
	p = 0;
	while ((i < len) && str[i])
	{
		p = 0;
		while ((i + p < len) && (to_find[p] == arr[i + p])
			&& (to_find[p] != '\0'))
			p++;
		if (to_find[p] == '\0')
			return (arr + i);
		i++;
	}
	return (0);
}

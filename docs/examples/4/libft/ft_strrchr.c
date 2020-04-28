/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:55:40 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 18:55:42 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*arr;
	size_t	i;

	i = ft_strlen(s);
	arr = (char *)s;
	while (i > 0)
	{
		if (arr[i] == (char)c)
			return (arr + i);
		i--;
	}
	if (*arr == (char)c)
		return (arr);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:16:30 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/01 16:16:33 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*arr;
	size_t	len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		arr = (char*)malloc(sizeof(char) * (len + 1));
		if (!arr)
			return (NULL);
		while (s[i])
		{
			arr[i] = f(s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}

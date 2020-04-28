/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:13:10 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/01 17:13:15 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			arr[i] = f(i, s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}

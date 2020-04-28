/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:48:09 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/30 18:48:18 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*arr;

	arr = (char *)s;
	while (*arr)
	{
		if (*arr == (unsigned char)c)
			return (arr);
		arr++;
	}
	if (*arr == (unsigned char)c)
	{
		return (arr);
	}
	return (NULL);
}

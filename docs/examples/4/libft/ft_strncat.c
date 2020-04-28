/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:45:51 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/06 10:45:53 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	start_index;

	start_index = ft_strlen(dest);
	i = 0;
	while (i < n && src[i])
	{
		dest[start_index + i] = src[i];
		i++;
	}
	dest[start_index + i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:40:33 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/06 10:40:45 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	start_index;

	start_index = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[start_index + i] = src[i];
		i++;
	}
	dest[start_index + i] = '\0';
	return (dest);
}

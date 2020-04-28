/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:57:19 by arudenko          #+#    #+#             */
/*   Updated: 2017/10/27 14:12:58 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)str)[i] = (unsigned char)value;
		i++;
	}
	return (str);
}

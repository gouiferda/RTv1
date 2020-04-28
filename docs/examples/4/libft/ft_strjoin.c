/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:00:31 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/01 18:00:33 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		i = -1;
		j = 0;
		arr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!arr)
			return (NULL);
		while (s1[++i])
			arr[i] = s1[i];
		while (s2[j])
		{
			arr[i] = s2[j];
			i++;
			j++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}

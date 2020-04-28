/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:15:21 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/01 18:15:23 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		first_index(char const *str)
{
	int	len;
	int	i;

	if (str)
	{
		len = 0;
		i = 0;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
				len = 0;
			else if (++len == 1)
				return (i);
			i++;
		}
	}
	return (0);
}

static	int		last_index(char const *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while ((str[len] == ' ' || str[len] == '\n' ||
	str[len] == '\t') && len > 0)
		len--;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*arr;
	int		first;
	int		last;
	int		i;

	if (s)
	{
		first = first_index(s);
		last = last_index(s);
		i = 0;
		if ((last - first) == 0)
			return (ft_strdup(""));
		arr = (char *)malloc(sizeof(char) * ((last - first) + 2));
		if (!arr)
			return (NULL);
		while (first <= last)
		{
			arr[i] = s[first];
			i++;
			first++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}

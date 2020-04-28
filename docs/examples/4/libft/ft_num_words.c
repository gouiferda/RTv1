/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:56:35 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/09 15:56:38 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_words(char const *str, char c)
{
	int		i;
	int		numwords;
	int		len;

	if (str)
	{
		i = 0;
		numwords = 0;
		len = 0;
		while (str[i])
		{
			if (str[i] == c)
				len = 0;
			else if (++len == 1)
				numwords++;
			i++;
		}
		return (numwords);
	}
	return (0);
}

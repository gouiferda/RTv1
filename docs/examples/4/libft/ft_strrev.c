/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:44:39 by arudenko          #+#    #+#             */
/*   Updated: 2017/12/21 13:38:17 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	if (str)
	{
		i = 0;
		j = ft_strlen(str) - 1;
		while (i < j)
		{
			tmp = str[j];
			str[j] = str[i];
			str[i] = tmp;
			i++;
			j--;
		}
	}
	return ;
}

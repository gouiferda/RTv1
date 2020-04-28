/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:36:29 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 19:30:26 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	num;
	int					negative;

	i = 0;
	num = 0;
	negative = 1;
	while (ft_white(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && (str[i]))
	{
		if ((num > 922337203685477580 || (num == 922337203685477580
		&& (str[i] - '0') > 7)) && negative == 1)
			return (-1);
		else if ((num > 922337203685477580 || (num == 922337203685477580
		&& (str[i] - '0') > 8)) && negative == -1)
			return (0);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return ((int)(num * negative));
}

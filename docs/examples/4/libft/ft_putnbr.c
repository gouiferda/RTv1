/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:40:32 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/02 16:40:35 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long arr[10];
	long long i;
	long long tmp;

	i = 0;
	tmp = n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = tmp * (-1);
	}
	arr[i++] = tmp % 10;
	tmp = tmp / 10;
	while (tmp != 0)
	{
		arr[i++] = tmp % 10;
		tmp = tmp / 10;
	}
	while (i != 0)
		ft_putchar(arr[--i] + '0');
}

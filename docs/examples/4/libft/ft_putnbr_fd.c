/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:20:40 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/02 17:20:42 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long arr[10];
	long long i;
	long long tmp;

	i = 0;
	tmp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(arr[--i] + '0', fd);
}

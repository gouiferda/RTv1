/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:31:10 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/02 12:31:11 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_len(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*arr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	arr = (char*)malloc(sizeof(char) * (arr_len(n) + 1));
	if (!arr)
		return (NULL);
	sign = (n < 0) ? -1 : 1;
	n *= sign;
	i = 0;
	while (n > 0)
	{
		arr[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		arr[i++] = '-';
	arr[i] = '\0';
	ft_strrev(arr);
	return (arr);
}

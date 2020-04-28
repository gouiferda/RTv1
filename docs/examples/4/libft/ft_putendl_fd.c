/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:13:45 by arudenko          #+#    #+#             */
/*   Updated: 2017/11/02 17:13:47 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	return ;
}

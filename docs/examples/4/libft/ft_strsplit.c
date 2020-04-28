/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:33:00 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/09 16:37:03 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		*num_charinword(char const *str, char c)
{
	int		*arr;
	int		flag;
	int		j;

	arr = (int*)malloc(sizeof(int) * ft_num_words(str, c));
	flag = 1;
	j = 0;
	while (*str)
	{
		if (*str == c)
			flag = 1;
		else
		{
			if (flag == 1)
			{
				flag = 0;
				j++;
				arr[j - 1] = 1;
			}
			else
				arr[j - 1]++;
		}
		str++;
	}
	return (arr);
}

static	int		*char_index_start(char const *str, char c)
{
	size_t	i;
	int		j;
	int		*arr;
	int		flag;

	arr = (int*)malloc(sizeof(int) * ft_num_words(str, c));
	i = 0;
	j = 0;
	flag = 1;
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
			{
				flag = 0;
				j++;
				arr[j - 1] = i;
			}
		}
		i++;
	}
	return (arr);
}

static	void	split(char const *s, char c, char **arr)
{
	int	wordnum;
	int	lenword;
	int	*n;
	int	*k;

	n = num_charinword(s, c);
	k = char_index_start(s, c);
	wordnum = 0;
	while (wordnum < ft_num_words(s, c))
	{
		lenword = -1;
		if (!(arr[wordnum] = (char*)malloc(sizeof(char) * (n[wordnum] + 1))))
			return ;
		while (++lenword < n[wordnum])
			arr[wordnum][lenword] = s[k[wordnum] + lenword];
		arr[wordnum][lenword] = '\0';
		wordnum++;
	}
	free(n);
	free(k);
	arr[wordnum] = 0x00;
}

char			**ft_strsplit(char const *s, char c)
{
	char **arudenko;

	if (s)
	{
		arudenko = (char**)malloc(sizeof(char*) * (ft_num_words(s, c) + 1));
		if (!arudenko)
			return (NULL);
		split(s, c, arudenko);
		return (arudenko);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:55:08 by arudenko          #+#    #+#             */
/*   Updated: 2017/12/21 10:51:23 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		search_nl(char *str)
{
	size_t		i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (0);
}

static int			read_file(int fd, char **str)
{
	int			ret;
	char		*tmp_buff;
	char		*tmp;
	int			i;

	i = 0;
	tmp_buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp_buff, BUFF_SIZE)) > 0)
	{
		i += ret;
		tmp_buff[ret] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, tmp_buff);
		ft_strdel(&tmp);
		if (ft_strchr(*str, '\n'))
		{
			ft_strdel(&tmp_buff);
			return (i);
		}
	}
	ft_strdel(&tmp_buff);
	if (ret == 0 && !ft_strchr(*str, '\n'))
		return (ft_strlen(*str));
	return (-1);
}

static int			read_again(const int fd, char **line, char **str)
{
	int			ret;
	char		*tmp;

	ret = read_file(fd, str);
	if (ret < 0)
		return (-1);
	else if (ret > 0)
	{
		if (ft_strchr(*str, '\n'))
		{
			*line = ft_strsub(*str, 0, (search_nl(*str)));
			tmp = *str;
			*str = ft_strsub(*str, search_nl(*str) + 1, ft_strlen(*str));
			ft_strdel(&tmp);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strdel(str);
		}
		return (1);
	}
	else
		return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char *str[12000];
	char		*cifym;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (ret = read(fd, *line, 0)) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	cifym = ft_strchr(str[fd], '\n');
	while (cifym == NULL)
	{
		if ((ret = read_again(fd, line, &str[fd])) < 0)
			return (-1);
		else if (ret > 0)
			return (1);
		else
			return (0);
	}
	*line = ft_strsub(str[fd], 0, (search_nl(str[fd])));
	tmp = str[fd];
	str[fd] = ft_strsub(str[fd], search_nl(str[fd]) + 1, ft_strlen(str[fd]));
	ft_strdel(&tmp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:25:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/01/25 10:26:21 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

char	*stock_str(char *buf, char *str)
{
	char *tmp;

	if (!str)
		str = ft_strdup(buf);
	else
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

char	*stock_line(char *str, char **line)
{
	char	*tmp;
	size_t		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < ft_strlen(str))
	{
		tmp = str;
		*line = ft_substr(str, 0, i);
		str = ft_substr(str, i + 1, ft_strlen(str));
		free(tmp);
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char *str;
	char		buf[BUFF_SIZE + 1];
	size_t			i;

	if ((BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		str = stock_str(buf, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (str)
		str = stock_line(str, line);
	if (str == NULL)
		return (0);
	return (1);
}

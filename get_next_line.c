/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:57:06 by emende            #+#    #+#             */
/*   Updated: 2021/12/31 21:02:43 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_joinandfree(char **line, char **arr)
{
	char	*new;

	new = *line;
	*line = ft_strjoin(*line, *arr);
	if (!(*line))
		return (-1);
	free(new);
	return (0);
}

static int	ft_malloc_buffer(char **arr)
{
	free (*arr);
	*arr = ft_strnew(BUFF_SIZE);
	if (*arr == NULL)
		return (-1);
	return (0);
}

static int	ft_last_part(char **line, char **arr, char *eol)
{
	char	*new;

	eol[0] = '\0';
	ft_joinandfree(line, arr);
	if (!*line)
		return (-1);
	new = *arr;
	*arr = ft_strdup(eol + 1);
	if (*arr == NULL)
		return (-1);
	free(new);
	return (1);
}

static int	ft_fill(char **line, char **arr, int fd, char *eol)
{
	ssize_t	ret;

	while (!eol)
	{
		if (ft_joinandfree(line, arr) == -1 || ft_malloc_buffer(&arr[fd]) == -1)
			return (-1);
		ret = read(fd, *arr, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if (strlen(*line) > 0)
			{
				**arr = '\0';
				return (1);
			}
			ft_strdel(arr);
			ft_strdel(line);
			return (0);
		}
		(*arr)[ret] = '\0';
		eol = ft_strchr(*arr, '\n');
	}
	return (ft_last_part(line, arr, eol));
}

int	get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE];
	char		*eol;

	eol = NULL;
	if (fd < 0 || fd > FD_SIZE || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!arr[fd])
		ft_malloc_buffer(&arr[fd]);
	if (!arr[fd])
		return (-1);
	*line = ft_strnew(0);
	eol = ft_strchr(arr[fd], '\n');
	return (ft_fill(line, &arr[fd], fd, eol));
}

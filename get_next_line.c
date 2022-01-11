/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emende <emende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:57:06 by emende            #+#    #+#             */
/*   Updated: 2022/01/10 13:24:50 by emende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_joinandfree(char **line, char **arr)
{
	char	*new;

	new = ft_strjoin(*line, *arr);
	if (!new)
		return (-1);
	free(*line);
	//free(*line);
	//*line = NULL;
	*line = new;
	return (0);
}

static int	ft_malloc_buffer(char **arr)
{
	free(*arr);
	*arr = ft_strnew(BUFF_SIZE);
	if (*arr == NULL)
		return (-1);
	return (0);
}

static int	ft_last_part(char **line, char **arr, char *eol)
{
	char	*new;
	//long	res;

	//res = eol - *arr + 1;
	*eol = '\0';
	ft_joinandfree(line, arr);
	//if (!(*line))
	//	return (-1);
	new = ft_strdup(eol + 1);
	if (!new)
		return (-1);
	//free(*arr);
	*arr = new;
	//if((*arr + res) != NULL)
	//*arr = *arr + res;
	//if (*arr == NULL)
	//	return (-1);
	return (1);
}

static int	ft_fill(char **line, char **arr, const int fd, char *eol)
{
	ssize_t	ret;
	//char	*head[FD_SIZE];

	//head[fd] = arr[fd];
	while (!eol)
	{
	//	ft_joinandfree(line, arr);
	//	ft_malloc_buffer(&arr[fd], &head[fd]);
	//	head[fd] = arr[fd];
		if (ft_joinandfree(line, arr) == -1 || ft_malloc_buffer(arr) == -1)
			return (-1);
		ret = read(fd, *arr, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if (ft_strlen(*line))
			{
				**arr = '\0';
				return (1);
			}
			//if (*arr)
			ft_strdel(arr); /* this break function */
			ft_strdel(line); /* if enabled there is (NULL) in end */
			return (0);
		}
		(*arr)[ret] = '\0';
		eol = ft_strchr(*arr, '\n');
	}
	return (ft_last_part(line, arr, eol));
}

int	get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE + 1];
	char		*eol;

	if (fd < 0 || fd > FD_SIZE || !line || BUFF_SIZE <= 0)
		return (-1);
//	if (!arr[fd])
//		return (-1);

	//*line = NULL;
	//if (line && *line)
	*line = ft_strnew(0);
//	if (*line == NULL)
//		return (-1);
	if (!arr[fd])
		ft_malloc_buffer(&arr[fd]);
	eol = ft_strchr(arr[fd], '\n');
	return (ft_fill(line, &arr[fd], fd, eol));
}

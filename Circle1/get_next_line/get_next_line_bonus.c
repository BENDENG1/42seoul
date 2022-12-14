/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:16 by gyroh             #+#    #+#             */
/*   Updated: 2022/11/17 19:52:32 by gyroh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_newline(char **line, int rsize)
{
	char	*res;
	char	*tmp;
	int		pos;

	if (!line || !*line || rsize < 0)
		return (NULL);
	pos = check_newline(*line);
	if (pos > -1)
	{
		res = ft_substr(*line, 0, pos + 1);
		tmp = ft_substr(*line, pos + 1, ft_strlen(*line) - (pos + 1));
		free(*line);
		*line = tmp;
		if (**line != '\0')
			return (res);
	}
	else
		res = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (res);
}

static int	add_rsize(int rsize, int fd, char *buff, char **line)
{
	char	*tmp;

	while (rsize > 0)
	{
		buff[rsize] = '\0';
		if (!line[fd])
			line[fd] = ft_strdup("");
		if (!line[fd])
			return (-2);
		tmp = line[fd];
		line[fd] = ft_strjoin(tmp, buff);
		free(tmp);
		if (!line[fd])
			return (-2);
		if (check_newline(line[fd]) > -1)
			break ;
		rsize = read(fd, buff, BUFFER_SIZE);
	}
	return (rsize);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rsize;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rsize = read(fd, buff, BUFFER_SIZE);
	rsize = add_rsize(rsize, fd, buff, line);
	if (rsize == -2)
		return (NULL);
	if (!line[fd])
		return (NULL);
	return (get_newline(&line[fd], rsize));
}

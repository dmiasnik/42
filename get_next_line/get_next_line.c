/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:09:46 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/10/17 11:37:50 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_join(char *str1, char *str2)
{
	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	return (ft_strjoin(str1, str2));
}

static char	*free_null(char **str)
{
	if (*str)
		free(*str);
	*str = 0;
	return (NULL);
}

static char	*get_next(int fd, char **last)
{
	char	*buf;
	ssize_t	r;
	char	*t;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free_null(last));
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = 0;
		t = get_join(*last, buf);
		free_null(last);
		*last = t;
		if (ft_strchr(buf, '\n'))
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (r < 0)
		free_null(last);
	free(buf);
	return (*last);
}

static char	*get_line(char **last)
{
	char	*temp;
	char	*t;
	char	*line;

	temp = ft_strchr(*last, '\n');
	t = NULL;
	line = NULL;
	if (temp)
	{
		line = ft_substr(*last, 0, temp - *last + 1);
		if (ft_strlen(*last) - (temp - *last + 1) > 0)
			t = ft_substr(temp, 1, ft_strlen(*last) - (temp - *last + 1));
		if (*last)
			free(*last);
		*last = t;
		return (line);
	}
	line = *last;
	*last = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lastbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lastbuf || !ft_strchr(lastbuf, '\n'))
		get_next(fd, &lastbuf);
	if (!lastbuf)
		return (NULL);
	line = get_line(&lastbuf);
	if (!line && lastbuf)
	{
		free(lastbuf);
		lastbuf = 0;
	}
	return (line);
}
/*
#include <fcntl.h>
int main(int q, char *a[])
{
	//char * t = get_next_line(0);
	//if (t)
	//	write(1, t, ft_strlen(t));

	int f = open(a[1], 0);
	char *t = get_next_line(f);
	while (t)
	{
		write(1, t, ft_strlen(t));
		t = get_next_line(f);
	}

	//t = get_next_line(f);
	//if (t)
	//	write(1, t, ft_strlen(t));

	close(f);
	return 0;
}*/

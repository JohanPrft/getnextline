/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:49 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/05 18:20:57 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endlinestr(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	trim_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] != '\0')
		i++;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		buff[j] = buff[i];
		j++;
		i++;
	}
	buff[j] = '\0';
}

char	*get_strbuff(char	*buff)
{
	int		i;
	char	*str;

	i = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = buff[i];
	i++;
	str[i] = '\0';
	trim_buff(buff);
	return (str);
}

char	*make_stach(int fd, char buff[BUFFER_SIZE + 1], char *stach)
{
	int			bytes;

	while (!(endlinestr(stach)))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			buff[0] = 0;
			return (NULL);
		}
		if (bytes == 0)
		{
			buff[0] = 0;
			break ;
		}
		buff[bytes] = '\0';
		stach = ft_strjoin(stach, buff);
	}
	return (stach);
}

/*
**	function that send the line read from a file descriptor
**	null if nothing is left or error
*/

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*stach;

	stach = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stach, 0))
	{
		if (fd >= 0)
			ft_bzero(buff, BUFFER_SIZE);
		return (NULL);
	}
	if (endlinestr(buff))
		return (get_strbuff(buff));
	if (buff[0] != '\0')
		stach = ft_strjoin(stach, buff);
	stach = make_stach(fd, buff, stach);
	trim_buff(buff);
	return (stach);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *s;
	int	i;

	fd = open("txt_test/haddock.txt", O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s != NULL)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (0);
}

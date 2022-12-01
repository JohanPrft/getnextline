/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:49 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/01 19:13:01 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	function that send the line read from a file descriptor
**	null if nothing is left or error
*/

#include "get_next_line.h"


int	endlinebuff(char *str)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	endlinestach(char *str)
{
	size_t	i;

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

	i = 0;
	while (buff[i] != '\n' && i < BUFFER_SIZE - 1)
	{
		buff[i] = '\0';
		i++;
	}
	buff[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*stach;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	stach = malloc(0);
	if (!stach)
		return (NULL);
	i = 0;
	while (buff[i] == '\0' && i < BUFFER_SIZE)
		i++;
	if (i != BUFFER_SIZE)
		stach = ft_strjoin(stach, &buff[i]);
	while (!endlinestach(stach))
	{
		if (read(fd, buff, BUFFER_SIZE) != BUFFER_SIZE)
			return (NULL);
		stach = ft_strjoin(stach, buff);
	}
	if (endlinebuff(buff))
		trim_buff(buff);
	return (stach);
}

char	*get_next_line(int fd)
{
// declarations
	static char	*buff;
	char 		*stach;
	size_t		i;

// initialisation
	buff = malloc(1);
	if (!buff)
		return (NULL);

// verifier les parametres et autres
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stach, 0))
		return (NULL)
// chaine de renvoi stach

// si buff non vide faire une premiere copie a partir de l'ancien \n

// lire dans le fichier

// copier ce qui a ete lu jusqua tomber sur un '\n'

// dans buff remplacer ce qui est jusquau \n par \0

// renvoyer la stach qui contient une ligne finissant par \n
}


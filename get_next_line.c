/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:49 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/05 11:13:48 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	function that send the line read from a file descriptor
**	null if nothing is left or error
*/

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
	while (buff[i] != '\n')
		i++;
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

char	*get_next_line(int fd)
{
// declarations
	static char	buff[BUFFER_SIZE + 1];
	char 		*stach;

// initialisation
	stach = NULL;

// verifier les parametres et autres
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, stach, 0))
		return (NULL);
// si \n dans buff return
	if (endlinestr(buff))
		return (get_strbuff(buff));
// si buff n'est pas vide
	if (buff[0] != '\0')
		stach = ft_strjoin(stach, buff);
// tant qu'il n'y a pas de /n dans stach copier ce qui a ete lu
	while (!(endlinestr(stach)))
	{
		// tcheck read pour fin de fichier
		if (read(fd, buff, BUFFER_SIZE) == 0)
			return(NULL);
		stach = ft_strjoin(stach, buff);
	}
//  modif buffer, deplacer apres le /n au debut (y compris le '\0')
	trim_buff(buff);
// renvoyer la stach qui contient une ligne finissant par \n
	return (stach);
}

// int	main(void)
// {
// 	int	fd;
// 	char *s;
// 	int	i;

// 	fd = open("41_no_nl.txt", O_RDONLY);
// 	printf("%i\n", fd);
// 	s = get_next_line(fd);
// 	i = 0;
// 	while (s != NULL)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 		i++;
// 	}
// 	return (0);
// }

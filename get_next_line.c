/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:49 by jprofit           #+#    #+#             */
/*   Updated: 2022/11/30 17:52:28 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	function that send the line read from a file descriptor
**	null if nothing is left or error
*/

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	char	*stach;
	char	*buff;

	stach = malloc(0);
	if (!stach)
		return (NULL);
	buff = malloc(sizeof(*stach) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (buff )
	return (buff);
}

int	main(void)
{
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("%s", get_next_line(fd));
	return (0);
}

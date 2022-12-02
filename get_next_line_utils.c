/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:46:07 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/02 17:37:50 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*str;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] && s2[j - 1] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

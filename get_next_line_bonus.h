/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:40:46 by jprofit           #+#    #+#             */
/*   Updated: 2022/12/05 18:16:24 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);

#endif

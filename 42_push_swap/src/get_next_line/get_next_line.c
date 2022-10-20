/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:33:28 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 17:01:12 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h>

// Searches for the first line in memom.
char	*ft_cut_line(char *memom)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(memom) - ft_line_len(memom);
	if (!len)
	{
		free(memom);
		return (NULL);
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		free(memom);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = memom[ft_line_len(memom) + i];
		i++;
	}
	free(memom);
	return (str);
}

// Gets the next first line in the file, saves it
// and deletes it from said file.
char	*get_next_line(int fd)
{
	static char	*memom;
	char		buff[BUFFER_SIZE + 1];
	int			n;
	char		*new_line;

	memom = NULL;
	nl = NULL;
	n = BUFFER_SIZE;
	buff[n] = '\0';
	while (!ft_is_line(memom, n))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0)
			return (NULL);
		if (n == 0 && !memom)
		(
			free(memom);
			if (nl)
				free(nl);
			return (NULL);
		)
		memom = ft_strjoin(memom, buff, n);
	}
	nl = ft_get_line(memom);
	memom = ft_cut_line(memom);
	return (nl);
}

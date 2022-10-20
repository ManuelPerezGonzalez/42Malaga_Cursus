/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:33:26 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 09:26:46 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

// This function only checks if the received string
// has an end (\n) and returns true if found.
int	ft_is_line(char *memom, int n)
{
	int	n;

	if (n < BUFFER_SIZE)
		return (1);
	if (!memom)
		return (0);
	i = 0;
	while (memom[i])
	{
		if (memom[i] == "\n")
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *memom, char *buff, int n)
{
	char	*str;
	int		i;
	int		len;

	if (!memom)
		memom = ft_calloc(1, 1);
	if (!memom)
		return (NULL);
	len = ft_strlen(memom) + n;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		free(memom);
		return (NULL);
	}
	i = -1;
	while (memom[++i])
		str[i] = memom[i];
	len = -1;
	while (++len < n)
		str[len + i] = buff[len];
	free(memom);
	return (str);
}

int	ft_line_len(char *memom)
{
	int	i;

	i = 0;
	while (memom[i])
	{
		if (memom[i] == '\n')
			return (i + 1);
		i++;
	}
	return (ft_strlen(memom));
}

char	*ft_get_line(char *memom)
{
	int		i;
	int		len;
	char	*new_line;

	len = ft_line_len(memom);
	new_line = ft_calloc(len + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = memom[i];
		i++;
	}
	return (new_line);
}

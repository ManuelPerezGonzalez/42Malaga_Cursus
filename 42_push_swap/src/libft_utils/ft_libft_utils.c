/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:15:45 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 12:33:27 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_atoi(char *str, t_stacks *stacks)
{
	int		i;
	int		sign;
	long	finalint;

	i = 0;
	sign = 1;
	finalint = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			finalint = finalint * 10 + (str[i] - '0');
		else
			ft_error(stacks);
		i++;
	}
	finalint *= sign;
	if ((i > 10 && sign == 1) || (i < 11 && sign == -1) || finalint > 2147483647
		|| finalint < -2147483648)
		ft_error(stacks);
	return (finalint);
}

void	*ft_calloc(int amount, int size)
{
	int		i;
	char	*room;

	i = 0;
	room = malloc(amount * size);
	if (!room)
		return (0);
	while (i < amount * size)
		room[i++] = 0;
	return (room);
}

int	ft_strncmp(const char *s1, const char *s2, int number)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i] && s1[i] && s2[i]) && i < number - 1)
		i++;
	if (number == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

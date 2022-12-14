/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:40:48 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 13:31:02 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// The only purpose of this function is to show what is saved in every stack.
void	ft_print_struct(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("Stack A: ");
	while (i < stacks->max_size)
	{
		if (i < stacks->size_a || stacks->stack_a[i])
			printf(" %d ", stacks->stack_a[i]);
		else
			printf(" X ");
		i++;
	}
	printf("\n");
	i = 0;
	printf("Stack B: ");
	while (i < stacks->max_size)
	{
		if (i < stacks->size_b || stacks->stack_b[i])
			printf(" %d ", stacks->stack_b[i]);
		else
			printf(" X ");
		i++;
	}
	printf("\n");
}

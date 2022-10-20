/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:30:17 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 13:29:59 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// We all know to this point the "swap" functions, but here is used
// with a structure positions, only difference.
void	ft_swap_a(t_stacks *stack, int checkwrite)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	if (checkwrite)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stacks *stack, int checkwrite)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
	if (checkwrite)
		write(1, "sb\n", 3);
}

void	ft_swap_both(t_stacks *stacks, int checkwrite)
{
	ft_swap_a(stacks, 0);
	ft_swap_b(stacks, 0);
	if (checkwrite)
		write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:30:23 by maperez-          #+#    #+#             */
/*   Updated: 2022/11/02 10:22:56 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*These functions do exactly the same as in the rotate.c
file but the other way.*/
void	ft_reverse_rotate_a(t_stacks *stack, int checkwrite)
{
	if (stack->size_a < 2)
		return ;
	ft_push(stack->stack_a, stack->size_a, stack->stack_a[stack->size_a - 1]);
	if (checkwrite)
		write(1, "rra\n", 4);
}
	//ft_print_struct(stack);

void	ft_reverse_rotate_b(t_stacks *stack, int checkwrite)
{
	if (stack->size_b < 2)
		return ;
	ft_push(stack->stack_b, stack->size_b, stack->stack_b[stack->size_b - 1]);
	if (checkwrite)
		write(1, "rrb\n", 4);
}
	//ft_print_struct(stack);

void	ft_reverse_rotate_both(t_stacks *stack, int checkwrite)
{
	ft_reverse_rotate_b(stack, 0);
	ft_reverse_rotate_a(stack, 0);
	if (checkwrite)
		write(1, "rrr\n", 4);
}
	//ft_print_struct(stack);

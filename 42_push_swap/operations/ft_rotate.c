/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:30:20 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/21 13:13:09 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*Takes a stack and moves all of its numbers one position up
(first number, position 0, is now last, position stack_lenght - 1).*/
void	ft_rotate(int *stack, int stack_lenght, int number)
{
	int	i;

	i = 0;
	while (i < stack_lenght - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = number;
}

void	ft_rotate_a(t_stacks *stack, int checkwrite)
{
	if (stack->size_a < 2)
		return ;
	ft_rotate(stack->stack_a, stack->size_a, stack->stack_a[0]);
	if (checkwrite)
		write(1, "ra\n", 3);
}
	//ft_print_struct(stack);

void	ft_rotate_b(t_stacks *stack, int checkwrite)
{
	if (stack->size_b < 2)
		return ;
	ft_rotate(stack->stack_b, stack->size_b, stack->stack_b[0]);
	if (checkwrite)
		write(1, "rb\n", 3);
}
	//ft_print_struct(stack);

// Calls both rotation functions at the same time (considered one operation).
void	ft_rotate_both(t_stacks *stack, int checkwrite)
{
	ft_rotate_a(stack, 0);
	ft_rotate_b(stack, 0);
	if (checkwrite)
		write(1, "rr\n", 3);
}
	//ft_print_struct(stack);

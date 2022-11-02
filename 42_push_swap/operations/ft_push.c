/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:29:32 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/21 13:13:39 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*We use 'i' as the new "last position" of the stack we need to reorganize
and push all of its values towards it so the first position will remain "empty".
Then, assing the "pushed" number to it.*/
void	ft_push(int *stack, int stack_lenght, int number)
{
	int	i;

	i = stack_lenght - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = number;
}

// Deletes the last element of a stack after
// pushing its value to the other stack.
void	ft_remove_element(int *stack, int stack_len)
{
	int	i;

	i = 0;
	while (i < stack_len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = 0;
}

// Both of the next functions do the same task, push and remove an element
// from one of the stacks to the other
// Resize stack.
void	ft_push_a(t_stacks *stack, int checkwrite)
{
	if (stack->stack_b == 0)
		return ;
	ft_push(stack->stack_a, ++stack->size_a, stack->stack_b[0]);
	ft_remove_element(stack->stack_b, stack->size_b);
	stack->size_b--;
	if (checkwrite)
		write(1, "pa\n", 3);
}
	//ft_print_struct(stack);

void	ft_push_b(t_stacks *stack, int checkwrite)
{
	if (stack->stack_a == 0)
		return ;
	ft_push(stack->stack_b, ++stack->size_b, stack->stack_a[0]);
	ft_remove_element(stack->stack_a, stack->size_a);
	stack->size_a--;
	if (checkwrite)
		write(1, "pb\n", 3);
}
	//ft_print_struct(stack);

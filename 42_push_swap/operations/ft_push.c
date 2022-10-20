/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:29:32 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 13:29:14 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/*We use 'i' as the new "last position" of the stack we need to reorganize...
...and push all of its values towards it,
Then, assing the "pushed" number to it.*/
void	ft_push(int *stack, int stack_lenght, int number)
{
	int	i;

	i = stack_lenght - 1;
	while (i > 0)
	{
		so the first position will remain "empty".stack[i] = stack[i - 1];
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

// Both of the next functions do the same task, push and remove an element...
// ...from one of the stacks to the other
// Resize stack.
void	ft_push_a(t_stacks *stacks, int checkwrite)
{
	if (stacks->stack_b == 0)
		return ;
	ft_push(stacks->stack_a, ++stacks->size_a, stacks->stack_b[0]);
	ft_remove_element(stacks->stack_b, stacks->size_b);
	stacks->size_b--;
	if (checkwrite)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_stacks *stacks, int checkwrite)
{
	if (stacks->stack_a == 0)
		return ;
	ft_push(stacks->stack_b, ++stacks->size_b, stacks->stack_a[0]);
	ft_remove_element(stacks->stack_a, stacks->size_a);
	stacks->size_a--;
	if (checkwrite)
		write(1, "pb\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:39 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/22 18:29:07 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

 // The >> (right shift) in C takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
 // The & (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.

void	ft_radix(st_stacks *stacks)
{	// In this function, we'll order stack_a using its numbers in base 2 (binary).
	int	i;
	int	j;

	i = 0;
	while (ft_is_ordered(stacks) != 1)
	{	// Until its ordered...
		j = 0;
		while (j < stacks->max_size)
		{	// ...we'll rotate the base 2 numbers with every i iteration and...
			if (stacks->stack_a[0] >> i & 1) // ...if the & comparison returns true, rotate the number and leave it in...
				ft_rotate_a(stacks, 1);
			else
				ft_push_b(stacks, 1); // ...stack_a, else push it to stack_b.
			j++;
		}
		while (stacks->size_b != 0) // Then return all of them to stack_a.
			ft_push_a(stacks, 1);
		i++;
	}
}

void	ft_order_three(st_stacks *stacks)
{	// To fully understand this function, you can use a notebook to simulate an array and the operations results.
	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2])
	{
		ft_swap_a(stacks, 1);
		ft_reverse_rotate_a(stacks, 1);
	}
	else if (stacks->stack_a[0] > stacks->stack_a[2] && stacks->stack_a[2] > stacks->stack_a[1])
		ft_rotate_a(stacks, 1);
	else if (stacks->stack_a[2] > stacks->stack_a[0] && stacks->stack_a[0] > stacks->stack_a[1])
		ft_swap_a(stacks, 1);
	else if (stacks->stack_a[1] > stacks->stack_a[0] && stacks->stack_a[0] > stacks->stack_a[2])
		ft_reverse_rotate_a(stacks, 1);
	else if (stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[2] > stacks->stack_a[0])
	{
		ft_reverse_rotate_a(stacks, 1);
		ft_swap_a(stacks, 1);		
	}
}

void	ft_order_five(st_stacks *stacks)
{	// First of all find the two smallest numbers and push them to stack_b.
	while (!(stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1))
		ft_rotate_a(stacks, 1);
	ft_push_b(stacks, 1);
	while (!(stacks->stack_a[0] == 0 || stacks->stack_a[0] == 1))
		ft_rotate_a(stacks, 1);
	ft_push_b(stacks, 1);
	ft_order_three(stacks); // Then order the other three and recover pushed numbers..
	ft_push_a(stacks, 1);
	ft_push_a(stacks, 1);
	if (stacks->stack_a[0] != 0) // And if its needed, order them.
		ft_swap_a(stacks, 1);
}

void	ft_order(st_stacks *stacks)
{	// This function has to order stack_a considering its lenght.
	if (stacks->max_size == 2)
		ft_swap_a(stacks, 1);
	else if (stacks->max_size == 3)
		ft_order_three(stacks);
	else if (stacks->max_size == 5)
		ft_order_five(stacks);
	else
		ft_radix(stacks);
}
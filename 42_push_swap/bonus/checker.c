/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:51:33 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 10:59:43 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	ft_is_operation(char *op, t_stacks *stack)
{
	if (!ft_strncmp(op, "sa\n", 3))
		ft_swap_a(stack, 0);
	else if (!ft_strncmp(op, "sb\n", 3))
		ft_swap_b(stack, 0);
	else if (!ft_strncmp(op, "ss\n", 3))
		ft_swap_both(stack, 0);
	else if (!ft_strncmp(op, "pa\n", 3))
		ft_push_a(stack, 0);
	else if (!ft_strncmp(op, "pa\n", 3))
		ft_push_b(stack, 0);
	else if (!ft_strncmp(op, "ra\n", 3))
		ft_rotate_a(stack, 0);
	else if (!ft_strncmp(op, "rb\n", 3))
		ft_rotate_b(stack, 0);
	else if (!ft_strncmp(op, "rr\n", 3))
		ft_rotate_both(stack, 0);
	else if (!ft_strncmp(op, "rra\n", 4))
		ft_reverse_rotate_a(stack, 0);
	else if (!ft_strncmp(op, "rrb\n", 4))
		ft_reverse_rotate_b(stack, 0);
	else if (!ft_strncmp(op, "rrr\n", 4))
		ft_reverse_rotate_both(stack, 0);
	else
		ft_error(stack);
}

void	ft_check(t_stacks *stack)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		ft_is_operation(os, stack);
		op = get_next_line(0);
	}
	if (!ft_is_ordered(stack))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	stack = ft_initialize_stacks(++argc, argv - 1);
	ft_check(stack);
	ft_free_stacks(stack);
}

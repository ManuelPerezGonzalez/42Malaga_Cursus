/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:30:23 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 10:23:44 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// These functions do exactly the same as in the rotate.c file but the other way.
void    ft_reverse_rotate_a(st_stacks *stack, int checkwrite)
{
    if (stack->size_b < 2)
        return ;
    ft_push(stack->stack_a, stack->size_a, stack->stack_a[stack->size_a - 1]);
    if (checkwrite)
        write(1, "rra\n", 4);
}

void    ft_reverse_rotate_b(st_stacks *stack, int checkwrite)
{
    if (stack->size_b < 2)
        return ;
    ft_push(stack->stack_b, stack->size_b, stack->stack_b[stack->size_b - 1]);
    if (checkwrite)
        write(1, "rrb\n", 4);
}

void    ft_reverse_rotate_both(st_stacks *stacks, int checkwrite)
{
    ft_reverse_rotate_b(stacks, 0);
    ft_reverse_rotate_a(stacks, 0);
    if (checkwrite)
        write(1, "rrr\n", 4);
}
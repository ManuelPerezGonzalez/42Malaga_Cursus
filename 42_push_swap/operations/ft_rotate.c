/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:30:20 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 10:23:12 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void    ft_rotate(int *stack, int stack_lenght, int number)
{
    int i;
    // Takes a stack and moves all of its numbers one position up
    // (first number, position 0, is now last, position stack_lenght - 1).
    i = 0;
    while (i < stack_lenght - 1)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[i] = number;
}

void    ft_rotate_a(st_stacks *stacks, int checkwrite)
{
    if (stacks->size_a < 2)
        return ;
    ft_rotate(stacks->stack_a, stacks->size_a, stacks->stack_a[0]);
    if (checkwrite)
        write(1, "ra\n", 3);
}

void    ft_rotate_b(st_stacks *stacks, int checkwrite)
{
    if (stacks->size_b < 2)
        return ;
    ft_rotate(stacks->stack_b, stacks->size_b, stacks->stack_b[0]);
    if (checkwrite)
        write(1, "rb\n", 3);
}

ft_rotate_both(st_stacks *stacks, int checkwrite)
{ // Calls both rotation functions at the same time (considered one operation).
    ft_rotate_a(stacks, 0);
    ft_rotate_b(stacks, 0);
    if (checkwrite)
        write(1, "rr\n", 3);    
}
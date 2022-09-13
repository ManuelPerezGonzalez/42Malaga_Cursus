/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:42 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/13 11:12:30 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_ordered(st_stacks *stacks)
{
    int i;

    i = 1;
    while (i < stacks->size_a)
    { // This will only return '0' if a number is found to be minor than the previous one.
        if (stacks->stack_a[i] < stacks->stack_a[i - 1])
            return (0);
        i++;
    }
    return (1);
}

void    ft_fill_array(st_stacks *stacks, char **numbers)
{
    
}

void    ft_fill_stack(st_stacks *stacks, char **numbers, int n)
{
    char    **nums;

    if (n != 1) // If arguments number is more than 1, it means we can just fill...
        ft_fill_array(stacks, numbers); // ...a new array with them.
    else
    { // Otherwise, we received environment variable $ARG, so we have to...
        nums = ft_split(numbers[0], ' '); // ...split it into the required numbers.
        ft_fill_array(stacks, nums);
        free(nums);
    }
}
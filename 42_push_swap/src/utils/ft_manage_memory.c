/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:30 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/13 10:48:18 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void    ft_free_stacks(st_stacks *stacks)
{
    free(stacks->stack_a);
    free(stacks->stack_b);
    free(stacks);
    exir(0);
}

void    ft_free_struct(st_stacks *stacks)
{
    free(stacks);
    exit(0);
}

void    ft_free_stack_a(st_stacks *stacks)
{
    free(stacks->stack_a);
    free(stacks);
    exit(0);
}

void    ft_error(st_stacks *stacks)
{
    write(1, "Error", 5);
    ft_free_stacks(stacks);
}

st_stacks   *ft_initialize_stacks(char **numbers, int narg)
{
    struct s_stacks *stacks; // Declare a new struct of type s_stacks.
    int i;

    stacks = malloc(sizeof(struct s_stacks));
    if (!stacks) // Check for space.
        exit(0);
    if (narg != 1) // If the program received more than 1 argument through console, it means they are the numbers we have to order, 
        stacks->max_size = narg; // ...so it gives the stack the size of the number of arguments received.
    else // If not, count number of words saved in $ARG, being numbers[0] the numbers string.
        stacks->max_size = ft_count_words(numbers[0], ' ');
    stacks->size_a = stacks->max_size; // Give every variable in struct "stacks" a size.
    stacks->size_b = 0;
    // Check for memory space for both stacks...
    stacks->stack_a = ft_calloc((stacks->max_size + 1), sizeof(int));
    if (!stacks->stack_a) // ...if there's not enough for stack_a, free the struct...
        ft_free_struct(stacks);
    stacks->stack_b = ft_calloc((stacks->max_size + 1), sizeof(int));
    if (!stacks->stack_b) // ...if there's not enough for stack_b, first free stack a, then the struct.
        ft_free_stack_a(stacks);
    i = 0;
    while (i < stacks->max_size)
        stacks->stack_a[i++] = -1; // Initialize stack_a slots.
    ft_fill_stack(stacks, numbers, narg);
    return (stacks);
}
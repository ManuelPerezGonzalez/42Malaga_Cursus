/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:30 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 09:49:13 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_free_stacks(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	exit(0);
}

void	ft_free_struct(t_stacks *stacks)
{
	free(stacks);
	exit(0);
}

void	ft_free_stack_a(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks);
	exit(0);
}

void	ft_error(t_stacks *stacks)
{
	write(1, "Error\n", 6);
	ft_free_stacks(stacks);
}

// Declare a new struct of type s_stacks. Check for space.
// If the program received more than 1 argument through console,
// it means they are the numbers we have to order,
// so it gives the stack the size of the number of arguments received.
// If not, count number of words saved in $ARG,
// Give every variable in struct "stacks" a size.
// Check for memory space for both stacks.
// If there's not enough for stack_a.
// If there's not enough for stack_b first free stack a, then the struct.
// Initialize stack_a slots.
t_stacks	*ft_initialize_stacks(char **numbers, int narg)
{
	struct s_stacks	*stacks;
	int				i;

	stacks = malloc(sizeof(struct s_stacks));
	if (!stacks)
		exit(0);
	if (narg != 1)
		stacks->max_size = narg;
	else
		stacks->max_size = ft_count_words(numbers[0], ' ');
	stacks->size_a = stacks->max_size;
	stacks->size_b = 0;
	stacks->stack_a = ft_calloc((stacks->max_size + 1), sizeof(int));
	if (!stacks->stack_a)
		ft_free_struct(stacks);
	stacks->stack_b = ft_calloc((stacks->max_size + 1), sizeof(int));
	if (!stacks->stack_b)
		ft_free_stack_a(stacks);
	i = 0;
	while (i < stacks->max_size)
		stacks->stack_a[i++] = -1;
	ft_fill_stack(stacks, numbers, narg);
	return (stacks);
}

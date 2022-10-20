/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:42 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 11:03:31 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This will only return '0' if a number is found
// to be minor than the previous one.
int	ft_is_ordered(t_stacks *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < stacks->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

// Finds what position min is in aux, and replaces it, modifying the array
// with the minimun int possible so it wont be used
// again in ft_transform_array().
// Line 41 is very important for the ft_order.c file
// because it makes easier for us to reorganize the stack..
void	ft_replace_number(int *stack_a, int *aux, int min, int i)
{
	int	j;

	j = 0;
	while (aux[j] != min)
		j++;
	stack_a[j] = i;
	aux[j] = -2147483648;
}

// Using the max possible int in every i iteration,
// we'll find out which is the smallest number in aux.
// If we can find the minimun possible int in the first iteration,
// assing it to min and won't be changed (obviously); if not, the j loop
// will find the new min every time and replace it.
void	ft_transform_array(int *stack_a, int lenght, int *aux)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < lenght)
	{
		min = 2147483647;
		j = 0;
		while (j < lenght)
		{
			if ((i == 0 && aux[j] == -2147483648)
				|| (aux[j] < min && aux[j] != -2147483648))
				min = aux[j];
			j++;
		}
		ft_replace_number(stack_a, aux, min, i);
		i++;
	}
}

// Make sure with ft_atoi that the numbers have correct format
// and save them in a new and temporary array.
// And if we have a number duplicated, finish the program.
void	ft_fill_array(t_stacks *stacks, char **numbers)
{
	int	i;
	int	j;
	int	*temp;

	temp = ft_calloc(stacks->max_size + 1, sizeof(int));
	if (!temp)
		ft_free_stacks(stacks);
	i = 0;
	while (numbers[i])
	{
		j = 0;
		temp[i] = ft_atoi(numbers[i], stacks);
		while (j < i)
		{
			if (temp[j++] == temp[i])
			{
				free(temp);
				ft_free_stacks(stacks);
			}
		}
		i++;
	}
	ft_transform_array(stacks->stack_a, stacks->max_size, temp);
	free(temp);
}

// If arguments number is more than 1, it means we can just fill
// a new array with them. Otherwise, we received environment variable $ARG,
// so we have to split it into the required numbers.
void	ft_fill_stack(t_stacks *stacks, char **numbers, int n)
{
	char	**nums;

	if (n != 1)
		ft_fill_array(stacks, numbers);
	else
	{
		nums = ft_split(numbers[0], ' ');
		ft_fill_array(stacks, nums);
		free(nums);
	}
}

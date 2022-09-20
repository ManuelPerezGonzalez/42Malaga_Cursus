/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:42 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/20 10:06:37 by maperez-         ###   ########.fr       */
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

void    ft_replace_number(int *stack_a, int *aux, int min, int i)
{
    int j;

    j = 0;
    // Finds what position min is in aux, and replaces it, modifying the array
    // with the minimun int possible so it wont be used again in ft_transform_array().
    while (aux[j] != min)
        j++;
    stack_a[j] = i; // This line is very important for the ft_order.c file, because it makes easier for us to reorganize the stack.
    aux[j] = -2147483648;
}

void    ft_transform_array(int *stack_a, int lenght, int *aux)
{
    int i;
    int j;
    int min;

    i = 0;
    while (i < lenght)
    { // Using the max possible int in every i iteration,
      // we'll find out which is the smallest number in aux.
        min = 2147483647;
        j = 0;
        while (j < lenght)
        { // If we can find the minimun possible int in the first iteration,
          // assing it to min and won't be changed (obviously); if not, the j loop
          // will find the new min every time and replace it.
            if ((i == 0 && aux[j] == -2147483648)
                || (aux[j] < min && aux[j] != -2147483648))
                min = aux[j];
            j++;
        }
        ft_replace_number(stack_a, aux, min, i);
        i++;
    }
}

void    ft_fill_array(st_stacks *stacks, char **numbers)
{
    int i;
    int j;
    int *temp;

    temp = ft_calloc(stacks->max_size + 1, sizeof(int));
    if (!temp)
        ft_free_stacks(stacks);
    i = 0;
    while (numbers[i])
    {
        j = 0; // Make sure with ft_atoi that the numbers have correct format...
        temp[i] = ft_atoi(numbers[i], stacks); // ...and save them in a new and temporary array.
        while (j < i)
        { // And if we have a number duplicated, finish the program.
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
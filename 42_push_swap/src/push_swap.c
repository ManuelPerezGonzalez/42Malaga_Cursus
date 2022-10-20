/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:36:46 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/19 13:34:38 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* First of all we need to declare and initialize the stacks,
by giving the function the argument, which is $ARG,
that saves the numbers we want to order plus 1 (for memory, ++argv),
AND the number of arguments the function receives (argc - 1,
to not contemplate the program as argument).
If stack_a is not ordered, order it.*/
int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_initialize_stacks(++argv, argc - 1);
	if (ft_is_ordered(stacks) == 0)
		ft_order(stacks);
	ft_free_stacks(stacks);
}

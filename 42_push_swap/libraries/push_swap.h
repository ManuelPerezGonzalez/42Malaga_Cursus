/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:10 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/13 10:30:31 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Struct
typedef struct s_stacks
{
    int *stack_a;
    int *stack_b;
    int max_size;
    int size_a;
    int size_b;
}       st_stacks;

# endif
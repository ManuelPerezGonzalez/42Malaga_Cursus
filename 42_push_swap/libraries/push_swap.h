/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:10 by maperez-          #+#    #+#             */
/*   Updated: 2022/10/20 13:29:02 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Struct
typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		max_size;
	int		size_a;
	int		size_b;
}			t_stacks;

// Libft functions

int			ft_atoi(char *str, t_stacks *stacks);
void		*ft_calloc(int amount, int size);
int			ft_strncmp(const char *s1, const char *s2, int number);
int			ft_count_words(char const *s, char c);
char		**ft_split(char const *s, char c);

// Operations functions

void		ft_push_a(t_stacks *stacks, int write);
void		ft_push_b(t_stacks *stacks, int write);
void		ft_push(int *stack, int stack_lenght, int number);
void		ft_remove_element(int *stack, int stack_len);
void		ft_reverse_rotate_a(t_stacks *stack, int write);
void		ft_reverse_rotate_b(t_stacks *stack, int write);
void		ft_reverse_rotate_both(t_stacks *stacks, int write);
void		ft_rotate_a(t_stacks *stacks, int write);
void		ft_rotate_b(t_stacks *stacks, int write);
void		ft_rotate_both(t_stacks *stacks, int checkwrite);
void		ft_rotate(int *stack, int stack_lenght, int number);
void		ft_swap_a(t_stacks *stack, int write);
void		ft_swap_b(t_stacks *stack, int write);
void		ft_swap_both(t_stacks *stacks, int write);

// Memory functions

t_stacks	*ft_initialize_stacks(char **numbers, int narg);
void		ft_error(t_stacks *stacks);
void		ft_free_stack_a(t_stacks *stacks);
void		ft_free_struct(t_stacks *stacks);
void		ft_free_stacks(t_stacks *stacks);

// Utils functions

int			ft_is_ordered(t_stacks *stacks);
void		ft_replace_number(int *stack_a, int *aux, int min, int i);
void		ft_transform_array(int *stack_a, int lenght, int *aux);
void		ft_fill_array(t_stacks *stacks, char **numbers);
void		ft_fill_stack(t_stacks *stacks, char **numbers, int n);

// Order functions

void		ft_radix(t_stacks *stacks);
void		ft_order_three(t_stacks *stacks);
void		ft_order_five(t_stacks *stacks);
void		ft_order(t_stacks *stacks);

// Trash functions

void		ft_print_struct(t_stacks *stacks);

#endif